package year2013.round1a.a;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Problem {
	public static void main(String[] args) throws Exception{
		// GCJ共通 ここから
		String filename = "src/year2013/round1a/a/A-small-attempt0";
		PrintWriter out = new PrintWriter(new File(filename + ".out"));
		Scanner scan = new Scanner(new File(filename + ".in"));
		final int N = scan.nextInt();
		StringBuilder ret = new StringBuilder();
		for (int i = 0; i < N; i++) {
			ret.append("Case #"+(i+1)+": ");
			// 問題文を読んでsolve()に渡す ここから
			long r = scan.nextLong();
			long t = scan.nextLong();
			
			
			ret.append(solve(r,t));
			// 問題文を読んでsolve()に渡す ここまで
			ret.append("\n");
		}
		out.write(ret.substring(0, ret.length()-1));
		out.flush();
		// GCJ共通 ここまで
	}
	
	static int solve(long r, long t){
		int ret = 0;
		for(int k=1; ; k++){
			t-=(-3+4*k+2*r);
			if(t<0) break;
			ret++;
		}
		
		return ret;
	}
}
