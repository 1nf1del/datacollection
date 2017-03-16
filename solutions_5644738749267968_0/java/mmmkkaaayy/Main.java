package codejams;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;


public class Main {
	// debug switch
	public static final boolean debug = false;
	
	// target filename - will read fname.in, and output to fname.out
	public static final String fname = "files\\competition\\D-small-attempt3";

	
	public static void main(String[] args) {
		
		// program Object, change class for relevant program
		War prog = new War();
		
		try (BufferedReader br = new BufferedReader(new FileReader(fname+".in"))) {
			 
			PrintWriter pw = new PrintWriter(fname+".out");
			int testCases = Integer.parseInt(br.readLine());
			
			for (int i = 1;i <= testCases;i++) {
				pw.print("Case #"+i+": ");
				if (debug) System.out.println("====Test case "+i+"====");
				prog.testCase(br,pw);
				pw.print("\n");
				pw.flush();
			}
			 
		} catch (Exception e) {
			e.printStackTrace();
		} 

		System.out.println("Done!");
	}

}
