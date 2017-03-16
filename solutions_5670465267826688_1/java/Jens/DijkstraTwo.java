import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Jens Staahl
 */

public class DijkstraTwo {

	// some local config
	// static boolean test = false ;
	private boolean test = System.getProperty("ONLINE_JUDGE") == null;
	static String testDataFile = "C-large.in";
//	 static String testDataFile = "testdata.txt";
	private static String ENDL = "\n";
	// Just solves the acutal kattis-problem
	ZKattio io;
		
	int cnt = 0, max = 0;
	private void solve() throws Throwable {
		io = new ZKattio(stream);

		int n = io.getInt();
		for (int i = 0; i < n; i++) {
			solveIt(i+1);
			
		}
		out.flush();
	}


	boolean exit = false;
	boolean[] seen;
	long[] loopLength = new long[20];

	int[][] tm;

	private void solveIt(int casenr) {
		tm = new int[][]{
				{ 0 , 0, 0, 0, 0 },
				{ 0 , 1, 2, 3, 4 },
				{ 0 , 2,-1, 4,-3 },
				{ 0 , 3,-4,-1, 2 },
				{ 0 , 4, 3,-2,-1 },
		};

		long l = io.getLong(), x = io.getLong();
		String str = io.getWord();
		boolean can = false;

		for (int i = 1; i <= 4; i++) {
			for (int nCnt = 0; nCnt < 2; nCnt++) {
				boolean neg = nCnt == 1;
				int cur = neg ? -i : i;
				int start = cur;
				int cycle = -1;
				for (int j = 0; j < str.length()*20; j++) {
					if(j > 0 && j % str.length() == 0 && cur == start) {
						cycle = j / str.length();
						break;
					}
					cur = get(j, str, cur);
				}
				loopLength[start+10] = cycle;
			}
		}

		for (int a = 2; a <= 4; a++) {
			for (int b = 2; b <= 4; b++) {
				can |= canDo(new int[]{a,b}, x, str);
			}
		}
		
		print("Case #" + casenr + ": " + (can ? "YES" : "NO"));
	}
	
	private boolean canDo(int[] into, long x, String str) {
		int complete = 0, cur = 1;
		//give it 20 full tries per complete 1,2. then use looplength to calculate the last one
		long lastupdate = 0;
		for (long pos = 0; pos < x * str.length(); pos++) {
			if(complete == 2 &&pos % str.length() == 0) {
				long len = loopLength[cur + 10];
				if(len > 0) {
					long fullRuns = pos / str.length();
					long remRuns = x - fullRuns;
					long canSkip = (remRuns-1)/len;
					if(canSkip > 0) {
						pos += str.length() * canSkip*len;
					}
				}
			}
			if(complete < 2 && pos - lastupdate > 100L * str.length()) {
				return false;
			}
			cur = get(pos, str, cur);
			if(complete < 2 && pos < x * str.length() -1) {
				int next = get(pos + 1, str, 1);
				if (cur == (complete + 2) &&  next ==  into[complete]) {
					complete++;
					cur = 1;
					lastupdate = pos;
				}
			}
		}
		return complete == 2 && cur == 4;
	}

	int get(long pos, String s, int from){
		boolean neg =false;
		if (from < 0) {
			neg = true;
			from = Math.abs(from);
		}
		int mod = (int) (pos % s.length());
		int to = tm[from][s.charAt(mod) - 'i' + 2];
		if(to < 0) {
			neg = !neg;
			to = Math.abs(to);
		}
		return neg ? -to : to;
	};

	private void print(String string) {
		out.println(string);
		System.out.println(string);
	}


	public static void main(String[] args) throws Throwable {
		new DijkstraTwo().solve();
	}

	public DijkstraTwo() throws Throwable {
		if (test) {
			stream = new FileInputStream(testDataFile);
		}
	}

	InputStream stream = System.in;
//	PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));// outStream
	PrintWriter out = new PrintWriter(new File(this.getClass().getCanonicalName() + ".out")); //new OutputStreamWriter(System.out));// outStream

	public class ZKattio extends PrintWriter {
		public ZKattio(InputStream i) {
			super(new BufferedOutputStream(System.out));
			r = new BufferedReader(new InputStreamReader(i));
		}

		public ZKattio(InputStream i, OutputStream o) {
			super(new BufferedOutputStream(o));
			r = new BufferedReader(new InputStreamReader(i));
		}

		public boolean hasMoreTokens() {
			return peekToken() != null;
		}

		public int getInt() {
			return Integer.parseInt(nextToken());
		}

		public double getDouble() {
			return Double.parseDouble(nextToken());
		}

		public long getLong() {
			return Long.parseLong(nextToken());
		}

		public String getWord() {
			return nextToken();
		}

		private BufferedReader r;
		private String line;
		private StringTokenizer st;
		private String token;

		private String peekToken() {
			if (token == null)
				try {
					while (st == null || !st.hasMoreTokens()) {
						line = r.readLine();
						if (line == null)
							return null;
						st = new StringTokenizer(line);
					}
					token = st.nextToken();
				} catch (IOException e) {
				}
			return token;
		}

		private String nextToken() {
			String ans = peekToken();
			token = null;
			return ans;
		}
	}
	// System.out;

}