import java.io.*;

public class R1C_A {

	public static void main(String[] args) {
		try{
			//�����̐����Q�Ȃ�v�Z���s
			if(args.length == 2){
				exec(args[0],args[1],1,1);
			}else{
				System.out.println("usage : java CodeJam2011P_A [input filename] [output filename]");
			}
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}

	public final static void exec(String inFileName , String outFileName,int inDataPackRows , int loggingCycle) throws Exception{
		//���̓t�@�C���̃��[�_�[
		BufferedReader	inReader	= new BufferedReader(new FileReader(inFileName));
		//�o�̓t�@�C���̃��C�^�[
		PrintWriter		outWriter	= new PrintWriter(new BufferedWriter(new FileWriter(outFileName)));

		//���[�J���ϐ��̒�`
		String lineStr="",packStr="";
		int packRowCount=0,caseCount=0,caseNums=0;
		boolean isFirst=true;
		String outStr = null;
		int n = 0;
		boolean win = false;

		String[] stringArray = null;
	//��	String[] stringArray2 = new String[4];

		//���̓t�@�C�����P�s�ǂݍ��ށi�Ō�܂ōs���Ɣ�����j
		while((lineStr = inReader.readLine()) != null){

			if(isFirst){
				//�ŏ��̍s�̓P�[�X��
				caseNums = Integer.parseInt(lineStr);
				isFirst=false;
				win = false;
			}else{
				
				/*
				
				//2�s�ڈȍ~
				if ( packRowCount == 0 ){
					n = Integer.parseInt(lineStr);
					stringArray = new String[n];
				} else if ( packRowCount < n+1 ){
					stringArray[packRowCount - 1] = lineStr;
					//System.out.println(stringArray[packRowCount - 1]);
				}
				//�ǂݍ��񂾃e�L�X�g���o�b�t�@�ɒǉ�
				//packStr += lineStr +" ";
				packRowCount++;

				*/

				//�ǂݍ��񂾍s�����P�P�[�X���̍s���ɒB����ƌv�Z�����s
				if( packRowCount == 0 ){
					
					int sep = lineStr.indexOf("/");
					int a = Integer.parseInt(lineStr.substring(0,sep));
					int b = Integer.parseInt(lineStr.substring(sep + 1));
					
					int first = born(0, 0, a, b);
					//System.out.println(first);
									
					//�J�z����
					packStr="";
					packRowCount=0;
					caseCount++;
					
					String fmtOutStr;
					if (first == -1) {
						fmtOutStr="Case #" + String.valueOf(caseCount) + ": impossible";
					} else {
						fmtOutStr="Case #" + String.valueOf(caseCount) + ": " + first;
					}
					//�t�@�C���ɏ�������
					outWriter.println(fmtOutStr);
					
					//�r���o�߂�\��
					if(caseCount % loggingCycle == 0){
						System.out.println(fmtOutStr);
					}
				}
			}
		}
		
		outWriter.close();
		inReader.close();
		
		System.out.println("cases " + String.valueOf(caseCount) + " / " + String.valueOf(caseNums));
		if( caseCount != caseNums){
			System.out.println("cases unmatched");
		}
	}
	
	public static int born (int count, int first, int a, int b) {
		//System.out.println(a + "      " + b);
		count++;
		a = a * 2;
		if (a == b) {
			if (first == 0) {
				first = count;
			}
			return first;
		} else if (a >= b) {
			a = a - b;
			if (first == 0) {
				first = count;
			}
		}
		if (count > 40) {
			return -1;
		}
		return born(count, first, a, b);
	}

}
