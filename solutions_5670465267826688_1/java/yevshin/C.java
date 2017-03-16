import java.io.BufferedReader;
import java.io.InputStreamReader;


public class C {
	static final int[][] T = {
			{1, 2, 3, 4},
			{2,-1, 4,-3},
			{3,-4,-1, 2},
			{4, 3,-2,-1}
	};
	static int prod(int a, int b)
	{
		int sign = 1;
		if(a < 0)
			sign *= -1;
		if(b < 0)
			sign *= -1;
		return sign * T[Math.abs(a) - 1][Math.abs(b) - 1];
	}
	static int fromChar(char c)
	{
		switch(c)
		{
		case '1': return 1;
		case 'i': return 2;
		case 'j': return 3;
		case 'k': return 4;
		default:
			throw new AssertionError();
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int ntests = Integer.parseInt( reader.readLine() );
		for(int test = 1 ; test <= ntests; test++)
		{ 
			long x = Long.parseLong( reader.readLine().split(" ")[1] );
			String l = reader.readLine();
			String ans = solveLarge(x, l);
			System.out.println("Case #" + test + ": " + ans);
		}
	}
	
	private static String solveLarge(long x, String l)
	{
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < Math.min(x, 8 + x % 8); i++)
			sb.append(l);
		return solve(sb.toString());
	}
	
	private static String solve(String l) {
		int firstI = -1;
		int lastK = -1;
		int last = 1;
		for(int i = 0; i < l.length(); i++)
		{
			int li = fromChar( l.charAt(i) );
			last = prod(last, li);
			if(firstI == -1 && last == 2)
				firstI = i;
			if(last == 4)
				lastK = i;
		}
		String ans = firstI >= 0 && lastK > firstI && last == -1 ? "YES" : "NO";
		return ans;
	}
}
