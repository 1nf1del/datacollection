import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Ominous {
	static String file = "D-large";

	// static String file = "D";

	static boolean solve(int x, int r, int c) {
		if (((r * c) % x) != 0)
			return true;
		if (x == 1)
			return false;
		if (x == 2)
			return false;
		if (x == 3) {
			return !(Math.max(r, c) >= 3 && Math.min(r, c) != 1);
		}
		if (x == 4) {
			return Math.min(r, c) <= 2;
		}
		if (x == 5) {
			if (Math.min(r, c) == 4) {				
				return Math.max(r, c) == 4;
			}
			if (Math.min(r, c) <= 2)
				return true;
			if (Math.min(r, c) == 3) {
				
				boolean t22 = true;
				for (int i = 2; i < r * c - 5; i+=3) {
					int fh = (i);
					int sh = (r * c - 5 - i);
					if (fh % 3 == 0 && sh >= 0 && sh % 3 == 0)
						t22=false;
				}
				
				boolean t13 = true;
				for (int i = 3; i < r * c - 5; i+=3) {
					int fh = (i);
					int sh = (r * c - 5 - i);
					if (fh % 3 == 0 && sh >= 0 && sh % 3 == 0)
						return t13=false;
				}
				
				return (t22 || t13);			
			}
			
			return false;
		}
		if (x == 6) {
			if (Math.min(r, c) <= 2)
				return true;
			if (Math.min(r, c) == 3)
				return true;
			if (Math.min(r, c) == 4)
				return false;
			if (Math.min(r, c) >= 5)
				return false;
		}
		if (x >= 7)
			return true;

		 System.out.println(x + " " + r + " " + c);

		return false;
	}

	static int[] intArray(String l) {
		String[] vals = l.split(" ");
		int[] ans = new int[vals.length];
		for (int i = 0; i < vals.length; i++) {
			ans[i] = Integer.valueOf(vals[i]);
		}
		return ans;
	}

	public static void main(String[] args) throws IOException {
		FileInputStream fis = new FileInputStream(file + ".in");
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);

		FileOutputStream fos = new FileOutputStream(file + ".out");
		OutputStreamWriter isw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(isw);

		String line = null;
		List<String> lines = new ArrayList<String>();
		while ((line = br.readLine()) != null) {
			lines.add(line);
		}

		int problemCount = Integer.parseInt(lines.get(0));
		int currentIndex = 1;
		for (int i = 0; i < problemCount; i++) {
			String c = lines.get(currentIndex++);
			int[] a = intArray(c);

			String r = "Case #" + (i + 1) + ": " + (solve(a[0], a[1], a[2]) ? "RICHARD" : "GABRIEL");

			// System.out.println(r);
			bw.write(r);
			bw.newLine();
		}

//		for (int i = 1; i <= 20; i++) {
//			for (int j = 1; j <= 20; j++) {
//				for (int j2 = 1; j2 <= 20; j2++) {
//					solve(i, j, j2);
//				}
//			}
//		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();
	}
}
