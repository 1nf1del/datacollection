import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Chamath Kumarasinghe
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("a.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("a.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        FastScanner in = new FastScanner(inputStream);
        FastPrinter out = new FastPrinter(outputStream);
        TA solver = new TA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TA {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int t = in.nextInt();
            int cc = 0;
            while (t-- > 0) {
                cc++;
                System.out.print("Case #" + cc + ": ");
                out.print("Case #" + cc + ": ");

                int k = in.nextInt(), c = in.nextInt(), s = in.nextInt();

                if (s * c < k) {
                    System.out.println("IMPOSSIBLE");
                    out.println("IMPOSSIBLE");
                } else {
                    long[] pos = new long[s];
                    long kc_1 = 1;
                    int cp = 0;
                    for (int i = 0; i < c - 1; i++) {
                        kc_1 *= (long) k;
                    }
                    for (int i = 0; i < k; i++) {
                        pos[cp] += ((long) i) * kc_1;
                        cp++;
                        if (cp == s) {
                            cp = 0;
                            kc_1 /= (long) k;
                        }
                    }

                    for (int i = 0; i < s; i++) {
                        System.out.print((pos[i] + 1) + " ");
                        out.print((pos[i] + 1) + " ");
                    }

                    System.out.println();
                    out.println();


                }


            }
        }

    }

    static class FastScanner extends BufferedReader {
        public FastScanner(InputStream is) {
            super(new InputStreamReader(is));
        }


        public int read() {
            try {
                int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
                return ret;
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }

        static boolean isWhiteSpace(int c) {
            return c >= 0 && c <= 32;
        }

        public int nextInt() {
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int ret = 0;
            while (c >= 0 && !isWhiteSpace(c)) {
                if (c < '0' || c > '9') {
                    throw new NumberFormatException("digit expected " + (char) c
                            + " found");
                }
                ret = ret * 10 + c - '0';
                c = read();
            }
            return ret * sgn;
        }

        public String readLine() {
            try {
                return super.readLine();
            } catch (IOException e) {
                return null;
            }
        }

    }

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

        public void close() {
            super.close();
        }

    }
}

