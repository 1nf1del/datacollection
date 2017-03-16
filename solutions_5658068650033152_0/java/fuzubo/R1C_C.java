import java.io.*;

public class R1C_C {

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
					stringArray = new String[3];
					stringArray = lineStr.split(" ");
					int n = Integer.parseInt(stringArray[0]);
					int m = Integer.parseInt(stringArray[1]);
					int k = Integer.parseInt(stringArray[2]);
					System.out.println(n + " " +  m + " " +   k);
					int count = 0;
					int x = 0;
					if (n > m) {
						x = m;
					} else {
						x = n;
					}
					if (x == 1) {
						count = k;
					} else if (x == 2) {
						count = k;
					} else {
						int heihou = (int)Math.floor(Math.sqrt(k + 4));
						System.out.println(heihou);
						if (heihou > x) {
							heihou = x;
						}
						int y = (k + 4) / heihou;
						System.out.println(y);
						System.out.println(heihou * 4);
						count = (heihou + y - 4 )* 2 - heihou * y + k;
					}
					//System.out.println(first);
									
					//�J�z����
					packStr="";
					packRowCount=0;
					caseCount++;
					
					String fmtOutStr;
					fmtOutStr="Case #" + String.valueOf(caseCount) + ": " + count;

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
	
	public static int born (int count, int first, long a, long b) {
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
