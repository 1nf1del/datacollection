
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Random;
import java.util.Scanner;
import java.util.StringTokenizer;

public class GCJ_LastWord {

	void log(long[] X){
		int L=X.length;
		for (int i=0;i<L;i++){
			logWln(X[i]+" ");
		}
		log("");
	}

	void log(double[] X){
		int L=X.length;
		for (int i=0;i<L;i++){
			logWln(X[i]+" ");
		}
		log("");
	}

	void log(int[] X){
		int L=X.length;
		for (int i=0;i<L;i++){
			logWln(X[i]+" ");
		}
		log("");
	}
	void log(Object[] X){
		int L=X.length;
		for (int i=0;i<L;i++){
			logWln(X[i]+" ");
		}
		log("");
	}


	void log(Object o){
		logWln(o+"\n");
	}

	void logWln(Object o){
		System.out.print(o);
		//	outputWln(o);

	}
	void info(Object o){
		System.out.println(o);
		//output(o);
	}


	String solveBourrin(String s){
	
		int L=s.length();
		int MX=1<<L;
		String best=s;
		for (int x=0;x<MX;x++){
			String t="";
			for (int u=0;u<L;u++){
				int m=1<<u;
				if ((x&m)==0){
					t=s.charAt(u)+t;
				} else {
					t=t+s.charAt(u);
				}
			}
			if (t.compareTo(best)>0){
				best=t;
			}
		}
		return best;
	}
	
	String solveSubtil(String s){
		
		int L=s.length();
		String t=""+s.charAt(0);
		for (int i=1;i<L;i++){
			if (s.charAt(i)>=t.charAt(0))
				t=s.charAt(i)+t;
			else
				t=t+s.charAt(i);
		}
		return t;
	}
	

	// Global vars
	StringTokenizer st;
	BufferedReader in;
	BufferedWriter out;



	void process() throws Exception {
		Locale.setDefault(Locale.US);




		//File inputFile=new File("B-large.in");
		File inputFile=new File("A.in");



		//		PrintWriter outputFile= new PrintWriter("B-large.out","UTF-8");
		PrintWriter outputFile= new PrintWriter("A.out","UTF-8");


		Scanner sc=new Scanner(inputFile);
		sc.useLocale(Locale.US);
		
		int T=sc.nextInt();
		for (int t=1;t<=T;t++){
		
			String org=sc.next();
			//String s=solveBourrin(org);
			String s=solveSubtil(org);
			System.out.println("Case #"+t+": "+s);
			outputFile.println("Case #"+t+": "+s);


		}



		sc.close();
		outputFile.close();


	}



	public static void main(String[] args) throws Exception {
		GCJ_LastWord J=new GCJ_LastWord();

		J.process();


	}






}
