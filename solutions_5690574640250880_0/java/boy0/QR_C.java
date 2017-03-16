package boy0;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class QR_C {
	public static void main(String[] args) throws IOException {
		String strLine;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		QR_C me = new QR_C();

		// me.init();

		strLine = br.readLine();
		int T = Integer.parseInt(strLine);
		String[] as;
		int r, c, m;
		// int y;
		for (int x = 1; x <= T; x++) {
			strLine = br.readLine();
			as = strLine.split(" ");
			r = Integer.parseInt(as[0]);
			c = Integer.parseInt(as[1]);
			m = Integer.parseInt(as[2]);
			System.out.println("Case #" + x + ":");
			me.exec1(r, c, m);
		}
	}

	private int priv_length = 0;

	public void init() {

	}

	public void exec1(int r, int c, int m) {
		// ������ ���: ���� 4ĭ�� c. / .. ���ڰ� ����� ��.
		// ���� ���: r = 1 , c = 1 , m = 0 , m = t - 1
		int t = r * c;
		if (m == 0) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (i == 0 && j == 0) {
						System.out.append('c');
					} else {
						System.out.append('.');
					}
				}
				System.out.println();
			}
			return;
		} else if (m == t - 1) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (i == 0 && j == 0) {
						System.out.append('c');
					} else {
						System.out.append('*');
					}
				}
				System.out.println();
			}
			return;
		} else if (r == 1 && m < c) {
			for (int j = 0; j < c; j++) {
				if (j == 0) {
					System.out.append('c');
				} else if (j < c - m) {
					System.out.append('.');
				} else {
					System.out.append('*');
				}
			}
			System.out.println();
			return;
		} else if (c == 1 && m < r) {
			for (int i = 0; i < r; i++) {
				if (i == 0) {
					System.out.println('c');
				} else if (i < r - m) {
					System.out.println('.');
				} else {
					System.out.println('*');
				}
			}
			return;
		}
		if (m > t - 4) {
			System.out.println("Impossible");
			return;
		}

		// �����ϹǷ�, �׸��� �׷�����. ***..c ������.
		int[] mine_in_row = new int[r + 1]; // ���⼭�� 0���� �ƴ� 1���� r����
		for (int i = r; i >= 1; i--) {
			if (m > c - 1) {
				mine_in_row[i] = c;
			} else if (m == c - 1) {
				mine_in_row[i] = c - 2;
			} else { // m < c - 1
				mine_in_row[i] = m;
			}
			m -= mine_in_row[i];
			if (m == 0) {
				break;
			}
		}

		// ��°�� ħ���ϴ� ��� ���.
		m = m + mine_in_row[1] + mine_in_row[2];
		if (m != 0) {
			mine_in_row[1] = m / 2;
			mine_in_row[2] = m - mine_in_row[1];
			if (mine_in_row[1] != mine_in_row[2]) {
				// 1 row �� 2 row ���� mine ���ƾ� ��.
				if (r <= 2) {
					System.out.println("Impossible");
					return;
				}
				// 3 row ���� ���� ����.
				if (mine_in_row[3] == c) {
					mine_in_row[3] -= 3;
					mine_in_row[1] += 2;
					mine_in_row[2] += 1;
				} else {
					mine_in_row[3]--;
					mine_in_row[1]++;
				}
				// 2 row �� 3 row �� �� �׷������� Ȯ��
				if (mine_in_row[2] > mine_in_row[3]) {
					// 2nd row �� �� ���� �׸� �� ����.
					System.out.println("Impossible");
					return;
				}
			}
		}

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (i == 1 && j == c) {
					System.out.append('c');
				} else if (j > mine_in_row[i]) {
					System.out.append('.');
				} else {
					System.out.append('*');
				}
			}
			System.out.println();
		}
	}

	private boolean func_priv(int offset) {
		return true;
	}

}
