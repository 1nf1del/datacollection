import java.util.*;
import java.io.*;

public class X {

	void solve() {
		int smax = in.nextInt();
		String ss = in.next();
		int o = 0;
		int m = 0;
		for (int i = 0; i <= smax; i++) {
			int s = (int) (ss.charAt(i) - '0');
			if (s == 0) {
			} else if (o >= i)
				o += s;
			else {
				m += i - o;
				o += s + m;
			}
			System.out.println(s + " " + o + " " + m);
		}
		out.println(m);
		out.flush();
	}

	/*************************************************************************/

	public static void main(String[] args) throws Exception {
		main1();
	}

	public static void main0() {
		String s = "1 6 0000001";
		solveProblem0(s);
	}

	public static void main1() throws Exception {
		String load = "C:/Users/dmytrobukhantsov/Downloads/A-small-attempt1.in";
		String save = "C:/Users/dmytrobukhantsov/Downloads/A-small-attempt1.out";
		solveProblem1(load, save);
	}

	/*************************************************************************/

	static void solveAllCases() {
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			new X().solve();
		}
	}

	public static void solveProblem0(String s) {
		in = new Scanner(s);
		out = new PrintWriter(System.out);
		solveAllCases();
		out.flush();
	}

	public static void solveProblem1(String load, String save)
			throws FileNotFoundException {
		in = new Scanner(new File(load));
		out = new PrintWriter(new File(save));
		solveAllCases();
		out.close();
	}

	static Scanner in;
	static PrintWriter out;
}
