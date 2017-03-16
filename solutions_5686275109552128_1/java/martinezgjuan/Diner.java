import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Diner {

  static Reader sc = new Reader();
  static PrintWriter out = new PrintWriter(System.out);
  
  public static void main(String[] args) throws IOException {
    int t = sc.nextInt();

    for (int cas = 1; cas <= t; cas++) {
      int n = sc.nextInt();
      long[] p = new long[n];

      long maxNum = 0;
      for (int i = 0; i < n; i++) {
        p[i] = sc.nextLong();
        maxNum = Math.max(maxNum, p[i]);
      }
      
      long minTime = Long.MAX_VALUE / 2;
            
      for (long maxH = 1; maxH <= maxNum; maxH++) {
        long accum = 0;      
        for (int i = 0; i < n; i++) {
          long timesCur = 0;
          
          if(p[i] > maxH) {
            timesCur = p[i] % maxH == 0 ? (p[i] / maxH) - 1: (p[i] / maxH);
          }
          
          accum += timesCur;
        }
        
        minTime = Math.min(minTime, accum + maxH);
      }


      out.println("Case #" + cas + ": " + minTime);  
    }
    out.close();
  }

  /*
  public static void main(String[] args) throws IOException {
    int t = sc.nextInt();

    for (int cas = 1; cas <= t; cas++) {
      int d = sc.nextInt();
      ArrayList<Integer> p = new ArrayList<Integer>();

      for (int i = 0; i < d; i++) {
        p.add(sc.nextInt());
      }

      Collections.sort(p, Collections.reverseOrder());

      int justSplit = split(new ArrayList<Integer>(p));
      int justEat = eat(new ArrayList<Integer>(p));

      out.println("Case #" + cas + ": " + (Math.min(justSplit, justEat)));  
    }
    out.close();
  }

  static int split(ArrayList<Integer> p) {
    if(p.isEmpty()) {
      return 0;
    }

    int max = p.get(0);
    if(max >= 2) {
      int best = max;
      
      for (int i = 2; i <= max/2; i++) {
        ArrayList<Integer> changed = new ArrayList<Integer>(p);
        changed.set(0, max - i);
        changed.add(i);
        Collections.sort(changed, Collections.reverseOrder());
        int sp = split((new ArrayList<Integer>(changed)));
        int et = eat(new ArrayList<Integer>(changed));
        best = Math.min(best, Math.min(sp, et));
      }
           
      return best + 1;
      
    } else {
      return eat(p);
    }
  }

  static int eat(ArrayList<Integer> p) {
    if(p.isEmpty()) {
      return 0;
    }
    return p.get(0);
  }

  */
  static class Reader {
    final private int BUFFER_SIZE = 1 << 12; private byte[] buffer; private int bufferPointer, bytesRead; private boolean eof = false;
    public Reader() {buffer = new byte[BUFFER_SIZE];bufferPointer = bytesRead = 0;}
    public boolean reachedEOF() {return eof;}
    private void fillBuffer() throws IOException {bytesRead = System.in.read(buffer, bufferPointer = 0, BUFFER_SIZE); if (bytesRead == -1) { buffer[0] = -1;eof = true;}}
    private byte read() throws IOException {if (bufferPointer == bytesRead)fillBuffer();return buffer[bufferPointer++];}
    public String next() throws IOException {StringBuilder sb = new StringBuilder();byte c;while ((c = read()) <= ' ') {if (c == -1)return null;};do {sb.append((char) c);} while ((c = read()) > ' ');if (sb.length() == 0)return null;return sb.toString();}
    public String nextLine() throws IOException {StringBuilder sb = new StringBuilder();byte c;boolean read = false;while ((c = read()) != -1) {if (c == '\n') {read = true;break;}if (c >= ' ')sb.append((char) c);}if (!read)return null;return sb.toString();}
    public int nextInt() throws IOException {int ret = 0;byte c = read();while (c <= ' ')c = read();boolean neg = (c == '-');if (neg)c = read();do {ret = ret * 10 + c - '0';} while ((c = read()) >= '0' && c <= '9');if (neg)return -ret;return ret;}
    public long nextLong() throws IOException {long ret = 0;byte c = read();while (c <= ' ')c = read();boolean neg = (c == '-');if (neg)c = read();do {ret = ret * 10L + c - '0';} while ((c = read()) >= '0' && c <= '9');if (neg)return -ret;return ret;}
    public double nextDouble() throws IOException {double ret = 0, div = 1;byte c = read();while (c <= ' ')c = read();boolean neg = (c == '-');if (neg)c = read();do {ret = ret * 10 + c - '0';} while ((c = read()) >= '0' && c <= '9');if (c == '.')while ((c = read()) >= '0' && c <= '9')ret += (c - '0') / (div *= 10);if (neg)return -ret;return ret;}
    public int[] nextIntArrray(int n) throws IOException {int[] a = new int[n];for (int i = 0; i < n; i++)a[i] = nextInt();return a;}
    public int[][] nextIntMatrix(int n, int m) throws IOException {int[][] map = new int[n][m];for (int i = 0; i < n; i++)map[i] = nextIntArrray(m);return map;}
    public char[][] nextCharacterMatrix(int n) throws IOException {char[][] a = new char[n][];for (int i = 0; i < n; i++)a[i] = next().toCharArray();return a;}
    public void close() throws IOException {if (System.in == null)return;System.in.close();}
  }

  static void print(int[] A) {for(int i=0;i<A.length;i++){if(i!=0) out.print(' ');out.print(A[i]);}out.println();}
  static <T> void print(Iterable<T> A) {int i = 0;for(T act : A){if(i!=0)out.print(' ');out.print(act);i++;}out.println();}
  static void printPlus1(Iterable<Number> A) {int i = 0;for(Number act : A){if(i!=0)out.print(' ');out.print(act.longValue() + 1L);i++;}out.println();}
  static void debug(Object... o) { System.err.println(Arrays.deepToString(o)); }

  /*
	long s = System.currentTimeMillis();
	debug(System.currentTimeMillis()-s+"ms");
   */
}
