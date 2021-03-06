package codejam.year2014.round1C;

import java.util.*;
import java.io.*;
import java.math.*;

public class A {

	private static Scanner sc;

	public static void main(final String[] args) {
//		 setStreams("C:\\Users\\ybandiel\\Desktop\\testA");
		 setStreams("C:\\Users\\ybandiel\\Desktop\\A-small-attempt0");
		// setStreams("C:\\Users\\ybandiel\\Desktop\\A-large");
		sc = new Scanner(System.in);
		final int numCases = sc.nextInt();
		handleCases(numCases);
	}

	private static void setStreams(final String baseFileName) {
		try {
			System.setIn(new FileInputStream(baseFileName + ".in"));
			 System.setOut(new PrintStream(baseFileName + ".out"));
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void handleCases(final long numCases) {
		for (int i = 1; i <= numCases; i++) {
			handleCase(i);
		}
	}

	private static void handleCase(final int caseNumber) {
		String str = sc.next();
		String[] strarr = str.split("/");
		int P = Integer.valueOf(strarr[0]);
		int Q = Integer.valueOf(strarr[1]);
		int gdc = gcd(P, Q);
		
		int p = P/gdc;
		int q = Q/gdc;
		int count = 1;
		
		boolean ok = false;
		for(int i = 0 ; i < 50 ; i++) {
			if(Math.pow(2, i) == q) {
				ok = true;
				break;
			}
		}
		
		if(!ok) {
			System.out.println("Case #" + caseNumber + ": " + "impossible");
			return;
		}
		
		while (true) {
			if(Math.pow(2, count) * p >= q) {
				break;
			}
			count++;
		} 
		System.out.println("Case #" + caseNumber + ": " + count);
	}

	private static int gcd(int a, int b) {
	    BigInteger b1 = new BigInteger(""+a); // there's a better way to do this. I forget.
	    BigInteger b2 = new BigInteger(""+b);
	    BigInteger gcd = b1.gcd(b2);
	    return gcd.intValue();
	}
	private static void log(final String message) {
		System.out.println(message);
	}
}
