import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B
{
	public static void main(String[] args) throws Exception
	{
		out = new PrintWriter(new FileWriter("outB.txt"));
		int testCases = readInt();
		for (int t = 1; t <= testCases; t++)
		{
			int b = readInt();
			long m = readLong();

			if (Math.pow(2, b - 2) < m)
				out.printf("Case #%d: IMPOSSIBLE%n", t);
			else
			{
				int[][] g = new int[b][b];
				for (int i = 1; i < b; i++)
					g[0][i] = 1;

				long c = 1;

				int[] p = new int[b];
				p[b - 1] = 1;

				for (int i = b - 2; i >= 0; i--)
					for (int j = i + 1; j < b; j++)
					{
						if (c == m)
							break;

						if (c + p[j] <= m)
						{
							g[i][j] = 1;
							p[i] += p[j];
							c += p[j];
						}
					}

				if (c == m)
				{
					out.printf("Case #%d: POSSIBLE%n", t);
					for (int i = 0; i < b; i++)
					{
						for (int j = 0; j < b; j++)
							out.print(Math.min(1, g[i][j]));
						out.println();
					}
				}
				else
					out.printf("Case #%d: IMPOSSIBLE%n", t);
			}
		}
		out.close();
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static PrintWriter out = new PrintWriter(new BufferedWriter(
			new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	static String next() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException
	{
		return Long.parseLong(next());
	}

	static int readInt() throws IOException
	{
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException
	{
		return Double.parseDouble(next());
	}

	static char readChar() throws IOException
	{
		return next().charAt(0);
	}

	static String readLine() throws IOException
	{
		return br.readLine().trim();
	}

}
