import java.io.*;
import java.util.*; // ��� ����� ��� ���������, Random

// ��� ���������� � ���� �������������, ����� ��� ������ � ������ (�� �������� �� ��������)
public class __Solution {

	// ����������, ����������� ������� "����" ��� �� CF/timus
	static final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

	public static void main(String[] args) {
		new __Solution().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok;

	void init() throws FileNotFoundException {
		// ������������ ������� ��������/���������
		// System.in/System.out - ����������� ������ �����/������ �� �������

		if (ONLINE_JUDGE) {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
//			in = new BufferedReader(new InputStreamReader(System.in));
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
		}

		tok = new StringTokenizer("");
	}

	void run() {
		try {
			long timeStart = System.currentTimeMillis();

			init();

			int tests = readInt();
			for (int test = 1; test <= tests; ++test) {
				out.print("Case #" + test + ": ");
				solve();
			}

			out.close();

			long timeEnd = System.currentTimeMillis();
			System.err.println("Time = " + (timeEnd - timeStart));
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

	// ������ ������ ������ null, ���� ������ �� ��������
	String readLine() throws IOException {
		return in.readLine();
	}

	char[] readCharArray() throws IOException {
		return readLine().toCharArray();
	}

	// �������� �������, ���������� "������������� �����"
	// �� ��������� ��� ������ (������� ������ ��������� �����������)
	String delimiter = " ";

	String readString() throws IOException {
		while (!tok.hasMoreTokens()) {
			String nextLine = readLine();
			if (null == nextLine)
				return null;

			tok = new StringTokenizer(nextLine);
		}

		return tok.nextToken(delimiter);
	}

	int readInt() throws IOException {
		return Integer.parseInt(readString());
	}

	long readLong() throws IOException {
		return Long.parseLong(readString());
	}

	// ��� �� ����� ������ �������� �������
	void solve() throws IOException {
		int b = readInt();
		long m = readLong();
		
		boolean[][] a = new boolean[b][b];
		a[0][b-1] = true;
		--m;
		
		long[] p = new long[b];
		p[b-1] = 1;
		
		for (int v = b - 2; v > 0 && m > 0; --v) {
			long sum = 0;
			for (int u = v + 1; u < b && m > 0; ++u) {
				if (m >= p[u]) {
					sum += p[u];
					m -= p[u];
					a[v][u] = true;
				}
			}
			
			if (sum > 0) {
				a[0][v] = true;
				p[v] = sum;	
			}
		}
		
		if (m > 0) {
			out.println("IMPOSSIBLE");
		} else {
			out.println("POSSIBLE");
			for (int v = 0; v < b; ++v) {
				for (int u = 0; u < b; ++u) {
					out.print(a[v][u] ? 1 : 0);
				}
				out.println();
			}
		}
	}
}