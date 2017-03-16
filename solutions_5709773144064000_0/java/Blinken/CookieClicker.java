import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class CookieClicker {

	public CookieClicker(){}
	public static void main( String[] asArguments ){
		doProblem();
	}
	
	static void doProblem(){
		StringBuffer sbError = new StringBuffer();
		StringBuffer sbAnswer = new StringBuffer();
		String sAbsolutePath_input = "C:\\codejam\\Cookie Clicker\\B-small-attempt0.in";
		String sAbsolutePath_output = "C:\\codejam\\Cookie Clicker\\B-small-attempt0.out";
		ArrayList<String> listLines = zLoadLines( sAbsolutePath_input, 50000, sbError );
		int ctTestCases = 0;
		try {
			ctTestCases = Integer.parseInt( listLines.get( 0 ) );
			System.out.println( "test case count: " + ctTestCases ); 
		} catch( Throwable t ) {
			System.err.println( "count test cases: " + t );
			System.exit( -1 );
		}
		int xLine = 0;
		for( int xTestCase = 1; xTestCase <= ctTestCases; xTestCase++ ){
			xLine++;
			String sLine = listLines.get( xLine );
			String[] asParameters = split(sLine, ' ');
			double dFarmCost = Double.parseDouble(asParameters[0]);
			double dFarmProduction = Double.parseDouble(asParameters[1]);
			double dGoal = Double.parseDouble( asParameters[ 2 ] );
			double dCurrentRate = 2.0d;
			double dTimeSpentBuildingFarms = 0;
			double dBestTimeToGoal = dGoal / dCurrentRate;
			while( true ){
				dTimeSpentBuildingFarms += dFarmCost / dCurrentRate;
				if( dTimeSpentBuildingFarms > dBestTimeToGoal ) break;
				dCurrentRate += dFarmProduction;
				if( dTimeSpentBuildingFarms + dGoal / dCurrentRate < dBestTimeToGoal ){
					dBestTimeToGoal = dTimeSpentBuildingFarms + dGoal / dCurrentRate;
				}
			}

			// write output
			sbAnswer.append("Case #" + xTestCase + ": " + dBestTimeToGoal + "\n");
		}
		fileSave(sAbsolutePath_output, sbAnswer.toString(), sbError);
		System.out.println("wrote " + ctTestCases + " cases");
	}
	
	// loads lines in a file into an array list of lines
	// content can include newlines if in quotation marks
	// End of Line:
	//   PC - carriage return plus line feed
	//   Macintosh - carriage return
	//   UNIX - line feed (usually called "new line" in UNIX parlance)
	// ASCII code in decimal: LF = 10; CR = 13
	public static ArrayList<String> zLoadLines( String sAbsolutePath, int iEstimatedSize, StringBuffer sbError){
		if( sAbsolutePath == null ){ sbError.append("path missing"); return null; }
		StringBuffer sbContent = new StringBuffer(iEstimatedSize);
		if( !fileLoadIntoBuffer( sAbsolutePath, sbContent, sbError ) ){
			sbError.insert(0, "error loading file (" + sAbsolutePath + "): ");
			return null;
		}
		return zLoadLines( sbContent, sbError );
	}
	
	public static ArrayList<String> zLoadLines( StringBuffer sbContent, StringBuffer sbError ){
		return zLoadLines( sbContent.toString(), sbError );
	}
		
	public static ArrayList<String> zLoadLines( String sContent, StringBuffer sbError ){ 
		int lenContent = sContent.length();
		ArrayList<String> listLines = new ArrayList<String>();
		StringBuffer sbLine = new StringBuffer(120);
		int pos = 0;
		int eState = 1;
		while( pos < lenContent ){
			char c = sContent.charAt(pos);
			switch( eState ){
				case( 1 ): // in line
					if( c == 13 ){
						eState = 2; // after CR
					} else if( c == 10 ){ // end of UNIX line
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
					} else {
						sbLine.append(c);
					}
					pos++;
					break;
				case( 2 ): // after CR
					if( c == 10 ){ // reached end of PC line
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
						pos++;
						eState = 1;
					} else if( c == 13 ){ // two mac lines in a row (stay in CR state)
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
						pos++;
					} else { // single mac line
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
						eState = 1;
					}
			}
		}
		if( sbLine.length() > 0 ) listLines.add(sbLine.toString()); // add any unterminated lines at end
		return listLines;
	}
	
	public static boolean fileLoadIntoBuffer( String sAbsolutePath, StringBuffer sbResource, StringBuffer sbError){
		File file = new File(sAbsolutePath);
		if( !file.exists() ){
			sbError.append("file not found");
			return false;
		}
		java.io.InputStream inputstreamResource = null;
		try {
			inputstreamResource = new FileInputStream(file);
		} catch(Exception ex) {
			sbError.append("unable to open file: " + ex);
			return false;
		}
		return zLoadString( inputstreamResource, sbResource, sbError );
	}
	
	public static boolean zLoadString( java.io.InputStream inputstreamResource, StringBuffer sbResource, StringBuffer sbError){
		if( inputstreamResource == null ){
			sbError.append("resource input stream does not exist");
			return false;
		}
		BufferedReader brFileToBeLoaded = null;
		try {
			int iFileCharacter;
			brFileToBeLoaded = new BufferedReader(new InputStreamReader(inputstreamResource));
			while(true) {
				iFileCharacter = brFileToBeLoaded.read();
				if(iFileCharacter==-1) break;
				sbResource.append((char)iFileCharacter);
			}
		} catch(Exception ex) {
			sbError.append("Failed to read resource: " + ex);
			return false;
		} finally {
			try {
				if(brFileToBeLoaded!=null) brFileToBeLoaded.close();
			} catch(Exception ex) {
				sbError.append("Failed to close resource: " + ex);
				return false;
			}
		}
		return true;
	}
		public static boolean fileSave( String sAbsolutePath, String sContent, StringBuffer sbError){
		File file = new File(sAbsolutePath);
		return fileSave( file, sContent, sbError );
	}

	public static boolean fileSave(  File file, String sContent, StringBuffer sbError ){

		// if file does not exist, create it
		try {
			if( ! file.exists() ){
				file.createNewFile();
			}
		} catch( Exception ex ) {
			sbError.append("failed to create file " + file + ": " + ex );
			return false;
		}


		// open file
		java.io.FileOutputStream fos = null;
		try {
		    fos = new java.io.FileOutputStream(file);
		} catch(Exception ex) {
			sbError.append("failed to open file for writing: " + ex);
			return false;
		}

		// save to file
		try {
			fos.write( sContent.getBytes() );
		} catch(Exception ex) {
			System.err.println("write failure (" + sContent.length() + " bytes): " + ex);
			return false;
		} finally {
			try {
				if( fos!=null ) fos.close();
			} catch(Exception ex) {}
		}
		return true;
	}

	public static String[] split( String s, char c ){
		if( s == null ) return null;
		int ctChar = getOccurrenceCount(s, c);
		int ctSegments = ctChar + 1;
		String[] asSegments = new String[ctSegments];
		if( ctChar == 0 ){ // minimal case
			asSegments[0] = s;
			return asSegments;
		}
		int len = s.length();
		int xSegment = 0;
		int posStartOfSegment = 0;
		for(int pos = 0; pos < len; pos++){
			if( s.charAt(pos) == c ){
				asSegments[xSegment] = s.substring(posStartOfSegment, pos);
				posStartOfSegment = pos + 1; // skip delimiter
				xSegment++;
			}
		}
		asSegments[xSegment] = s.substring(posStartOfSegment, len);
		return asSegments;
	}

	public static int getOccurrenceCount(String s, char c){
		if( s == null ) return 0;
		int len = s.length();
		if( len == 0 ) return 0;
		int iCount = 0;
		for(int pos = 0; pos < len; pos++){
			if( s.charAt(pos) == c ) iCount++;
		}
		return iCount;
	}
	
}