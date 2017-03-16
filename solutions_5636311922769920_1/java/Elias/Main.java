import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main();
	}

	public Main() throws FileNotFoundException {
		// Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner(new File("D-large.in"));
		PrintWriter out = new PrintWriter(new File("D_large.out"));

		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			long k = sc.nextLong();
			long c = sc.nextLong();
			long s = sc.nextLong();

			long x = (long) Math.pow(k, c - 1);
			String sol = "";

			if (k == s && k == 1) {
				sol = "1";
			} else if (c == 1 && k <= s) {
				for (int i = 0; i < s; i++) {
					if (i != 0)
						sol += " ";
					sol += (x * i + 1);
				}
			} else if (c > 1 && k <= s + 1) {
				for (int i = 1; i <= s; i++) {
					if (i != 0)
						sol += " ";
					sol += (x * i + 1);
				}
			} else {
				sol = "IMPOSSIBLE";
			}

			System.out.println("Case #" + t + ": " + sol);
			out.println("Case #" + t + ": " + sol);
		}

		out.close();
		sc.close();
	}
}
