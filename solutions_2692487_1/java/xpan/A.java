
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class A {
	public static Scanner in;
	public static PrintWriter out;
	//public static final String IN_FILE = "input.txt";
	public static final String IN_FILE = "A-large.in";
	public static final String OUT_FILE = "A-large.out";
	
	public static void main(String[] args) throws IOException {
		in = new Scanner(new FileReader(IN_FILE));
		out = new PrintWriter(new FileWriter(OUT_FILE));
		
		int caseCount = in.nextInt();
		
		System.out.println(caseCount);
		
		for (int caseNum = 1; caseNum <= caseCount; caseNum++) {
			long A = in.nextLong();
			int N = in.nextInt();
			long[] motes = new long[N];
			for (int m = 0; m < N; m++) {
				motes[m] = in.nextLong();
			}
			Arrays.sort(motes);
			
			ArrayList<Value> po = new ArrayList<Value>();
			po.add(new Value(A, 0));
			for (int m = 0; m < N; m++) {
				ArrayList<Value> tmp = new ArrayList<Value>();
				for (Value v: po) {
					if (v.sum > motes[m]) {
						v.sum += motes[m];
						tmp.add(v);
					} else {
						Value s1 = new Value(v.sum, v.ops+1);//delete
						tmp.add(s1);
						if (v.sum > 1) {
							long running = v.sum;
							int step = 0;
							while (running <= motes[m]) {
								step++;
								running = 2 * running -1;
							}
							Value s2 = new Value(running+motes[m], v.ops+step);//add
							tmp.add(s2);
						}
					}
				}
				po = tmp;
				/*for (Value x: po)
					System.out.println(x.sum + ":" + x.ops);*/
			}
			long min = Long.MAX_VALUE;
			for (Value x: po)
				System.out.println(x.sum + ":" + x.ops);
			for (Value x: po) {
				min = Math.min(x.ops, min);
			}
			System.out.println("Processing test case: " + caseNum);
			out.print(String.format("Case #%d: %d%n", caseNum, min));
			//out.println();
			out.flush();
		}
		out.flush();
		out.close();
		in.close();
	}
	
	private static class Value {
		long sum;
		long ops;
		public Value(long sum, long ops) {
			this.sum = sum;
			this.ops = ops;
		}
	}
}
