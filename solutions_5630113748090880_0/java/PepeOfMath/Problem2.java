// Code by PepeOfMath
//
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class Problem2 {
    public static void main(String[] args) throws FileNotFoundException {
    	
        //hard code the file location
        //open file
        //get number of test cases
        File f = new File("B-small-attempt0.in");
        Scanner s = new Scanner(f);
        String line = s.nextLine();
        int T = Integer.parseInt(line);
        
        //open output file
        File f2 = new File("smalloutput.txt");
        PrintWriter p = new PrintWriter(f2);
        
        
        for ( int j = 1; j <= T; j++) {
        	int[] counts = new int[2500];
        	int n = s.nextInt();
        	for (int i = 0; i < 2*n*n-n; i++) {
        		int tmp = s.nextInt();
        		counts[tmp-1]++;
        	}
        	String result = "";
        	for (int i = 0; i < counts.length; i++) {
        		if (counts[i] % 2 != 0) {
        			result += (i+1) + " ";
        		}
        	}
			p.println("Case #" + j + ": " + result);
		   	
        
        }
        
        p.close();
        s.close();
    }
    
}
