import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Elf {
	private Scanner sc = new Scanner(System.in);
	private int next = 0;
	private String pq;
	private long P;
	private long Q;

	public void init() {
		pq = sc.next();

		int a = pq.lastIndexOf('/');
		P = Long.parseLong(pq.substring(0, a));
		Q = Long.parseLong(pq.substring(a + 1));

		long gcd = gcd(P, Q);
		P = P / gcd;
		Q = Q / gcd;

	}

	public void process() {
		long testQ = Q;
		while ((testQ - 1) % 2 != 0) {
			testQ = testQ / 2;
		}
		String result;
		if (testQ != 1) {
			result = "impossible";
		} else {
			int count = 1;
			while (P < Q / 2) {
				Q = Q / 2;
				count++;
			}
			result = count + "";
		}

		next++;
		System.out.println("Case #" + next + ": " + result);
	}

	public void run() {
		int size = sc.nextInt();
		for (int i = 0; i < size; i++) {
			init();
			process();
		}
		sc.close();
	}

	public static void main(String[] args) {
		new Elf().run();
	}

	public long gcd(long m, long n) {
		long a = Math.max(m, n);
		long b = Math.min(m, n);
		while (b > 0) {
			long r = a % b;
			a = b;
			b = r;
		}

		return a;
	}

}
