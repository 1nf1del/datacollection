import java.io.*;
import java.util.*;


public class C2 {
    public static void main(String[] arg) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader(new File("garbled_email_dictionary.txt")));
        String[] dict = new String[521196];
        for (int i = 0; i < dict.length; ++i) {
            dict[i] = br.readLine();
            for (char c : dict[i].toCharArray()) {
                assert 'a' <= c && c <= 'z';
            }
        }
        br.close();

        Scanner in = new Scanner(new File("C-large.in"));
        PrintWriter out = new PrintWriter("C-large.out");
        int T = in.nextInt();
        long time = System.currentTimeMillis();
        int totalLength = 0;

        for (int tn = 1; tn <= T; ++tn) {
            System.out.println(tn);
            String s = in.next();
            totalLength += s.length();

            final int[] D = new int[5 * (s.length() + 1)];
            Arrays.fill(D, INF);
            D[0] = 0;

            boolean[] u = new boolean[D.length];

            while (true) {
                int mi = -1;
                for (int i = 0; i < D.length; ++i) {
                    if (!u[i] && (mi == -1 || D[i] < D[mi])) {
                        mi = i;
                    }
                }
                if (mi / 5 == s.length()) break;
                u[mi] = true;
                loop:
                for (int i = 0; i < dict.length; ++i) {
                    final int len = dict[i].length();
                    final String t = dict[i];
                    final int index = mi / 5;
                    final int shift = mi % 5;
                    if (index + len > s.length()) continue;

                    int cost = 0;
                    int p = -5 + shift;
                    for (int j = 0; j < len; ++j) {
                        if (s.charAt(index + j) != t.charAt(j)) {
                            if (j - p < 5) {
                                continue loop;
                            } else {
                                p = j;
                                ++cost;
                            }
                        }
                    }

                    final int next = (index + len) * 5 + Math.max(0, p + 5 - len);

                    if (D[next] > D[mi] + cost) {
                        D[next] = D[mi] + cost;
                    }
                }
            }

            int ans = INF;
            for (int i = 0; i < 5; ++i) {
                ans = Math.min(ans, D[5 * s.length() + i]);
            }
            out.print("Case #" + tn + ": ");
            out.println(ans);
        }
        time = System.currentTimeMillis() - time;
        System.out.println(time);
        System.out.println(time * 1.0 / totalLength);

        out.close();
    }

    static final int INF = Integer.MAX_VALUE / 4;

}
