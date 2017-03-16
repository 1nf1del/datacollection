
/* @JUDGE_ID: 1848XX 2016CodeJamQualificationB Java */

import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    private Scanner stdin = new Scanner(System.in);
    private java.util.logging.Logger logger = null;
    public static String loggerName = "MainLogger";
    public boolean greedy=false;

    /**
     * Init class data here
     */
    private void init() {
	
    }

    /**
     * Handle the input here.
     * This method will call solve() method inside to solve the problem.
     * The return value indicates if there are more input data need to 
     * be handled. If it doesn't return 0, means this function have to be
     * called again to solve next data.
     * @return 0: end. 1: need to call input() again for next data.
     */
    private int input() {
	int ret=0;
	String com1;
	int T;

	if (stdin.hasNextInt()) {
	    T = stdin.nextInt();
	} else {
	    return ret;
	}

	for (int t1=0; t1<T; t1++) {
	    String panCake;
	    if (stdin.hasNext()) {
		panCake = stdin.next();
	    } else {
		return ret;
	    }
	    solve(panCake);
	    
	}

	ret=0;
    	return ret;
    }

    private int getbit(int n, int bit) {
	return (n>>bit)&0x01;
    }
    
    private int flip(int n, int s, int i) {
	int ret=0;
	for (int k1=0; k1<i; k1++) {
	    ret |= getbit(n, k1)<<k1;
	}
	for (int k1=s-1; k1>=i; k1--) {
	    ret |= (1-getbit(n, k1)) << (i - (k1 - (s-1)));
	}
	return ret;
    }
    private void solveSmall(String panCake) {
	int n = panCake.length();
	int[] table = new int[1<<n];
	Arrays.fill(table, -1);
	table[0]=0;
	boolean loopFlag=true;
	for (int i=0; i<table.length && loopFlag ; i++) {
	    loopFlag=false;
	    for (int j=0; j<table.length; j++) {
		if (table[j] == -1) {
		    loopFlag=true;
		}
		if (table[j] == i) {
		    for (int k=0; k<n; k++) {
			int nj=flip(j,n,k);
			if (table[nj]==-1) {
			    table[nj]=table[j]+1;
			}
		    }
		}
	    }
	}
	int aa1=0;
	for (int i=0; i<n; i++) {
	    if (panCake.charAt(i)=='+') {
		aa1 |= 0 << (n-i-1);
	    } else if (panCake.charAt(i)=='-') {
		aa1 |= 1 << (n-i-1);
	    }
	}
	output(table[aa1]);
    }


    private String flipS(String panCake, int k) {
	StringBuffer sb1 = new StringBuffer();
	for (int i=k; i>=0; i--) {
	    if (panCake.charAt(i)=='+') {
		sb1.append('-');
	    } else {
		sb1.append('+');
	    }
	}
	for (int i=k+1; i<panCake.length(); i++) {
	    sb1.append(panCake.charAt(i));
	}
	return sb1.toString();
    }
    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(String panCake) {
	if (panCake.length() <= 10 && !greedy) {
	    logInfo("Solved by brute-force");
	    solveSmall(panCake);
	    return;
	}
	/* Greedy */
	int count=0;
	boolean loopFlag=true;
	while (loopFlag) {
	    loopFlag=false;
	    for (int i=0; i<panCake.length(); i++) {
		if (panCake.charAt(i)=='-') {
		    loopFlag=true;
		    break;
		}
	    }
	    if (!loopFlag) {
		break;
	    }

	    int unsortedPancake=-1;
	    for (unsortedPancake=panCake.length()-1; unsortedPancake >= 0; unsortedPancake--) {
		if (panCake.charAt(unsortedPancake)=='-') {
		    break;
		}
	    }

	    if (panCake.charAt(0)=='-') {
		panCake = flipS(panCake, unsortedPancake);
		count++;
		continue;
	    }

	    int maxValue=-10000;
	    String solve1 = null;

	    for (int k=0; k<unsortedPancake; k++) {
		String s1;
		s1 = flipS(panCake, k);
		String s2;
		s2 = flipS(s1, unsortedPancake);
		int value=0;
		for (int k1=s2.length()-1; k1>=0; k1--) {
		    if (s2.charAt(k1)=='+') {
			value++;
		    } else {
			break;
		    }
		}
		if (value > maxValue) {
		    maxValue = value;
		    solve1 = s2;
		}
	    }
	    panCake = solve1;
	    count+=2;
	}
	output(count);
    }

    private int output_N=0;
    /**
     * Output the results
     */
    private void output(int X) {
	output_N++;
	System.out.format("Case #%1$d: %2$d%n",output_N,X);
    }


    /**
     * log information for debugging.
     */
    public void logInfo(String a, Object... args) {
	if (logger != null) {
	    logger.info(String.format(a,args));
	}
    }

    public void begin() {
	this.logger = java.util.logging.Logger.getLogger(Main.loggerName);
	if (this.logger.getLevel() != java.util.logging.Level.INFO) {
	    this.logger = null;
	}
	init();
	while (input()==1) {
	}
    }

    public void unittest() {
	this.logger = java.util.logging.Logger.getLogger(Main.loggerName);
    }

    public static void main (String args[]) {
	Main myMain = new Main();
	if (args.length >= 1 && args[0].equals("unittest")) {
	    myMain.unittest();
	    return;
	}
	java.util.logging.Logger.getLogger(Main.loggerName).setLevel(java.util.logging.Level.SEVERE);
	for (int i=0; args!=null && i<args.length; i++) {
	    if (args[i].equals("debug")) {
		java.util.logging.Logger.getLogger(Main.loggerName).setLevel(java.util.logging.Level.INFO);
	    }
	    if (args[i].equals("greedy")) {
		myMain.greedy=true;
	    }
	}
	myMain.begin();
    }
}
