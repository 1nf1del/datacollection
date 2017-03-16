import java.io.*;

public class CJ1A1 {
	public static void main (String[] args) {
		String fName = "A-large";
		try {
			BufferedReader inp = new BufferedReader(new FileReader(fName + ".in"));
			PrintWriter op = new PrintWriter(new FileWriter(fName + ".out"));
//			PrintStream op = System.out;
			String l = inp.readLine();
			String[] lArr;
			int n = Integer.parseInt(l);
			for (int ii = 1; ii <= n; ii++) {
				l = inp.readLine();
				lArr = l.split (" ");
				long r = Long.parseLong(lArr[0]), t = Long.parseLong(lArr[1]);
				long nRings = 1;
				while ((nRings * (2 * nRings - 1) + 2 * nRings * r) <= t)
					nRings = nRings << 1;
				nRings = nRings >> 1;
				long incr = nRings >> 1;
				long i = nRings;
				while (incr > 0) {
					for (; (i * (2 * i - 1) + 2 * i * r) <= t; i+=incr);
					i-=incr;
					incr = incr >> 1;
				}
//				for (i = nRings; (i * (2 * i - 1) + 2 * i * r) <= t; i++);
				op.println("Case #" + ii + ": " + i);
				System.out.println("Case #" + ii + ": " + i);
			}
			op.close();
			inp.close();
		}catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
