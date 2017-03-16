package boy0;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;

public class QR_D {
	public static void main(String[] args) throws IOException {
		String strLine;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		QR_D me = new QR_D();

		// me.init();

		strLine = br.readLine();
		int T = Integer.parseInt(strLine);
		String[] as;
		int y, z;
		for (int x = 1; x <= T; x++) {
			strLine = br.readLine();
			int n = Integer.parseInt(strLine);
			LinkedList<Integer> naomi = new LinkedList<Integer>();
			LinkedList<Integer> ken = new LinkedList<Integer>();
			strLine = br.readLine();
			as = strLine.split(" ");
			for (int i = 0; i < n; i++) {
				naomi.add((int) (Double.parseDouble(as[i]) * 1000000));
			}
			Collections.sort(naomi);
			strLine = br.readLine();
			as = strLine.split(" ");
			for (int i = 0; i < n; i++) {
				ken.add((int) (Double.parseDouble(as[i]) * 1000000));
			}
			Collections.sort(ken);
			y = me.exec_deceitful(n, new LinkedList<Integer>(naomi),
					new LinkedList<Integer>(ken));
			z = me.exec_war(n, new LinkedList<Integer>(naomi),
					new LinkedList<Integer>(ken));
			System.out.println("Case #" + x + ": " + y + " " + z);
			// System.out.println(naomi);
			// System.out.println(ken);
		}
	}

	private int priv_length = 0;

	public void init() {

	}

	public int exec_deceitful(int n, LinkedList<Integer> naomi,
			LinkedList<Integer> ken) {
		int y = 0;
		// War���� Ken �� ����: �� ���� ���� ������ ����. ������ ���� ���� ���� ������.
		// Deceitful War���� Naomi �� ����:
		// Ken�� ���� ���� �� ���� ���� ���� ��� ���� �ӿ� ������.
		// Ken�� ���� ���� �� ���� ���� ���� ���� ���� ����Ʈ ȹ��. Ken�� ���� ���� �� ���� ���ٰ� �ӿ��� Ken�� ����
		// ���� ������ �����ϴ� ���Ӽ�.

		for (int i = 0; i < n; i++) {
			Integer chosen_naomi = naomi.removeFirst(); // ������ ����.
			Integer min_ken = ken.getFirst();
			if (min_ken.compareTo(chosen_naomi) > 0) {
				// ken win
				ken.removeLast();
			} else {
				// naomi win
				y++;
				ken.removeFirst();
			}
		}

		return y;
	}

	public int exec_war(int n, LinkedList<Integer> naomi,
			LinkedList<Integer> ken) {
		int z = 0;
		// War���� Ken �� ����: �� ���� ���� ������ ����. ������ ���� ���� ���� ������.
		// War���� Naomi �� ����: ���� ���� �� ���� �ϳ��� ����.

		for (int i = 0; i < n; i++) {
			Integer chosen_naomi = naomi.removeLast(); // ū�� ����.
			Integer max_ken = ken.getLast();
			if (max_ken.compareTo(chosen_naomi) > 0) {
				// ken win
				ken.removeLast();
			} else {
				// naomi win
				z++;
				ken.removeFirst();
			}
		}

		return z;
	}

	private boolean func_priv(int offset) {
		return true;
	}

}
