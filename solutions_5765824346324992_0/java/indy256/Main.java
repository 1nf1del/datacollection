import java.io.FileInputStream;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int b = in.nextInt();
		int n = in.nextInt();
		int[] m = new int[b];
		for (int i = 0; i < b; i++) {
			m[i] = in.nextInt();
		}

		long lo = -1;
		long hi = 1000_000_000_000_000_00L;
		while (hi - lo > 1) {
			long mid = (lo + hi) >>> 1;

			long sum = 0;
			for (int i = 0; i < b; i++) {
				sum += mid / m[i] + 1;
			}

			if (sum < n) {
				lo = mid;
			} else {
				hi = mid;
			}
		}

		long time = hi;
		long sum = 0;
		for (int i = 0; i < b; i++) {
			sum += time / m[i] + 1;
		}

		long remain = sum - n;
		for (int i = b - 1; i >= 0; i--) {
			if (time % m[i] == 0) {
				if (remain == 0) {
					out.printf("Case #%d: %d\n", testNumber, i + 1);
					break;
				}
				--remain;
			}
		}
	}
}

class InputReader {
	final InputStream is;
	final byte[] buf = new byte[1024];
	int pos;
	int size;

	public InputReader(InputStream is) {
		this.is = is;
	}

	public int nextInt() {
		int c = read();
		while (isWhitespace(c))
			c = read();
		int sign = 1;
		if (c == '-') {
			sign = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res = res * 10 + c - '0';
			c = read();
		} while (!isWhitespace(c));
		return res * sign;
	}

	public String next() {
		int c = read();
		while (isWhitespace(c))
			c = read();
		StringBuilder sb = new StringBuilder();
		do {
			sb.append((char) c);
			c = read();
		} while (!isWhitespace(c));
		return sb.toString();
	}

	int read() {
		if (size == -1)
			throw new InputMismatchException();
		if (pos >= size) {
			pos = 0;
			try {
				size = is.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (size <= 0)
				return -1;
		}
		return buf[pos++] & 255;
	}

	static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

}

