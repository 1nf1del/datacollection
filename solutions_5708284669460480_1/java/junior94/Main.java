import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Agostinho Junior (junior94)
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		System.out.println(testNumber);
		int K = in.readInt();
		int L = in.readInt();
		int S = in.readInt();
		char[] keyboard = in.next().toCharArray();
		char[] target = in.next().toCharArray();

		int[] count = new int['Z' + 1];
		for (char c: keyboard) {
			count[c]++;
		}

		boolean possible = true;

		for (int i = 0; i < L; i++) {
			if (count[target[i]] == 0) {
				possible = false;
				break;
			}
		}

		double res;

		if (!possible) {
			res = 0;
		} else {
			double prob = 1.0;
			for (int i = 0; i < L; i++) {
				prob *= count[target[i]];
			}
			int max = getMax(target, S);
			res = max - prob * (S - L + 1) / Math.pow(K, L);
		}
		out.printfln("Case #%d: %.9f", testNumber, res);
	}

	private int getMax(char[] str, int S) {
		int n = str.length;
		int[] z = new int[n];

		z[0] = n;
		int l = 0;
		int r = 0;

		for (int i = 1; i < n; i++) {
			z[i] = Math.min(z[i - l], r - i + 1);

			while (i + z[i] < n) {
				if (str[z[i]] != str[i + z[i]]) {
					break;
				}
				z[i]++;
			}

			if (i + z[i] - 1 > r) {
				l = i;
				r = i + z[i] - 1;
			}

			r = Math.max(r, i);
		}

		int min = 0;

		for (int i = 1; i < n; i++) {
			if (i + z[i] == n) {
				min = i;
				break;
			}
		}
		
		if (min == 0) {
			return S / n;
		}

		int ans = 1;
		for (int i = min; i + n <= S; i += min) {
			ans++;
		}
		return ans;
	}

}

class InputReader {
	private BufferedReader input;
	private StringTokenizer line = new StringTokenizer("");

	public InputReader(InputStream in) {input = new BufferedReader(new InputStreamReader(in));
	}

	public void fill() {
		try {
			if(!line.hasMoreTokens()) line = new StringTokenizer(input.readLine());
		} catch(IOException io) { io.printStackTrace(); System.exit(0);}
	}

	public String next() {
		fill();
		return line.nextToken();
	}

	public int readInt() {
		fill();
		return Integer.parseInt(line.nextToken());
	}

}

class OutputWriter {
	private PrintWriter output;

	public OutputWriter(OutputStream out) {
		output = new PrintWriter(out);
	}

	public void printfln(String format, Object... o) {
		output.printf(format + "\n", o);
	}

	public void close() {
		output.close();
	}
}

