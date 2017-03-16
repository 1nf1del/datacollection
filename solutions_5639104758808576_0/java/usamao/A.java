import static java.util.Arrays.deepToString;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

public class A {
	static final boolean _PRACTICE = false;
	static final boolean _SMALL = true;
	static final boolean _FILEOUT = true;
	static final String _PROBLEM = "A";

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int k = 1; k <= t; k++) {
			System.out.print("Case #" + k + ": ");

			int count = sc.nextInt();
			int friend = 0;
			int standup = 0;
			String audience = sc.next();
			for (int i = 0; i <= count; i++) {
				if(standup < i){
					friend += i - standup;
					standup = i;
				}
				standup += audience.charAt(i) - '0';
			}
			System.out.println(friend);
		}
		if (sc != null) {
			sc.close();
		}
	}

	public static void main(String... args) throws IOException {
		FileInputStream is = null;
		PrintStream ps = null;
		if (_SMALL) {
			int i = 0;
			while (new File(_SMALLNAME(i) + ".in").exists())
				i++;
			i--;
			if (new File(_SMALLNAME(i) + ".out").exists()) {
				System.err.println("overwrite?(y/n)");
				char c = (char) System.in.read();
				if (c != 'y') {
					return;
				}
			}
			System.setIn(is = new FileInputStream(_SMALLNAME(i) + ".in"));
			if (_FILEOUT) {
				System.setOut(ps = new PrintStream(_SMALLNAME(i) + ".out"));
			}
			new A().run();
		} else {
			System.setIn(is = new FileInputStream(_LARGENAME() + ".in"));
			if (_FILEOUT) {
				System.setOut(ps = new PrintStream(_LARGENAME() + ".out"));
			}
			new A().run();
		}
		if (is != null)
			is.close();
		if (ps != null)
			ps.close();
	}

	private static String _LARGENAME() {
		return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
	}

	private static String _SMALLNAME(int a) {
		return _PROBLEM + "-small"
				+ (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
	}
}
