import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class googlerese {
	static String next() {
		if (st == null || !st.hasMoreTokens())
			nextLine();
		return st.nextToken();
	}

	static int nextInt() {
		return Integer.parseInt(next());
	}

	static void nextLine() {
		try {
			st = new StringTokenizer(f.readLine());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static StringTokenizer st;
	static PrintWriter out;
	static BufferedReader f;

	public static void main(String[] args) throws IOException {
		f = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		 PrintStream out = new PrintStream("googlerese.out");
		String key = "yhesocvxduiglbkrztnwjpfmaq ";
		int N = nextInt();
		for (int x = 1; x <= N; x++) {
			String s = f.readLine();
			StringBuffer sb = new StringBuffer();
			for (char c : s.toCharArray()) {
				if (Character.isLetter(c)) {
					sb.append(key.charAt(c - 'a'));
				} else
					sb.append(c);
			}
			out.printf("Case #%d: %s\n", x, sb);
		}
		out.close();
		// System.exit(0);
	}

}