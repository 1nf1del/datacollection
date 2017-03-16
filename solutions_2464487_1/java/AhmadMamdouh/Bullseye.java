import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;

public class Bullseye {
	public static long solve(long r, long t) {
		long step = 1;
		long curr = 0;
		while (true) {
			curr += step;
			long v = 2 * curr * curr - curr + 2 * r * curr;
			if (v <= t) {
				step *= 2;
			} else {
				long low = curr - step, high = curr;
				int itr = 100;
				while (itr-- > 0) {
					long mid = (low + high) / 2;
					if (2 * mid * mid - mid + 2 * r * mid <= t)
						low = mid;
					else
						high = mid;
				}
				return low;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		// System.out.println(1000);
		// Random rand = new Random();
		// for(int i=0;i<1000;i++){
		// long rad = Math.abs(rand.nextLong());
		// long tt = Math.abs(rand.nextLong());
		// System.out.println(rad+" "+tt);
		// }
		InputReader r = new InputReader(new FileReader("A.txt"));
		PrintWriter out = new PrintWriter(new FileWriter("A.out"));
		int T = r.nextInt();
		int test = 1;
		while (T-- > 0) {
			long radius = r.nextLong();
			long t = r.nextLong();
			long low = 1, high = (long) Math.min(Math.sqrt(t), t / (2 * radius)	+ 1);
			int itr = 100;
			while (itr-- > 0) {
				long mid = (low + high) / 2;
				if (2 * mid * mid - mid + 2 * radius * mid <= t)
					low = mid;
				else
					high = mid;
			}
			out.printf("Case #%d: %d\n", test, low);
			test++;
		}
		out.close();
	}

	static class InputReader {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public InputReader(FileReader stream) {
			reader = new BufferedReader(stream);
			tokenizer = null;
		}

		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
