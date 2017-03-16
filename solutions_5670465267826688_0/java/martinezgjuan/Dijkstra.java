import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Dijkstra {
  
  static Reader sc = new Reader();
  static PrintWriter out = new PrintWriter(System.out);
  
  // i = 2, j = 3, k = 4
  static int[][] table = {{ 1,  2,  3,  4},
                          { 2, -1,  4, -3},
                          { 3, -4, -1,  2},
                          { 4,  3, -2, -1}};
  
  static int op(int a, int b) {
        return Integer.signum(a)*Integer.signum(b) * table[Math.abs(a)-1][Math.abs(b)-1];
  }
  
  static int removeFirst(int whole, int first) {

    int index = 0;
    for (int i = 0; i < 4; i++) {
      if (Math.abs(table[first - 1][i]) == Math.abs(whole)) {
        index = i;
        break;
      }
    }

    return (index + 1) * Integer.signum(whole) * Integer.signum(first) *  Integer.signum(table[first-1][index]);
  }
  
  public static void main(String[] args) throws IOException {
    
    int t = sc.nextInt();
    
    for (int cas = 1; cas <= t; cas++) {
      
      int len = sc.nextInt();
      int times = sc.nextInt();
      
      String input = sc.next();
      
      if (len*times < 3) {
        out.println("Case #" + cas + ": " + "NO");
        continue;
      }
            
      int[] letters = new int[len * times];
      
      int product = 1;
      
      for (int i = 0; i < len * times; i++) {
        letters[i] = ((int)input.charAt(i%len) - 'i') + 2;
        product = op(product, letters[i]);
      }
      
      if (product != -1) {
        out.println("Case #" + cas + ": " + "NO");
        continue;
      }
      
      int prod1 = letters[0];
      int prod2 = letters[1];
      int remF = removeFirst(product, letters[0]);
      int prod3 = removeFirst(remF, letters[1]);
      
      boolean done = false;
      
      if(prod1 == 2 && prod2 == 3 && prod3 == 4) {
        done = true;
        out.println("Case #" + cas + ": " + "YES");
        continue;
      }
      
      int begSecond = 1;
      int begThird = 2;
      
      int totalLen = len * times;
      while(!done && !(begSecond == totalLen - 2 && begThird == totalLen - 1)) {
        int curProd2 = prod2;
        int curProd3 = prod3;
        begThird = begSecond + 1;
        
        // Move until there's a match for prod1
        while(!done && prod1 != 2 && !(begSecond == totalLen - 2 && begThird == totalLen - 1)) {
          curProd3 = removeFirst(curProd3, letters[begThird]);
          curProd2 = op(curProd2, letters[begThird]);
          curProd2 = removeFirst(curProd2, letters[begSecond]);
          prod1 = op(prod1, letters[begSecond]);
          begSecond++;
          begThird++;
        }
        
        if(prod1 == 2 && curProd2 == 3 && curProd3 == 4) {
          done = true;
          break;
        }
        
        // Update the base products 2 and 3
        if(prod1 == 2) {
          prod2 = curProd2;
          prod3 = curProd3;
        } else {
          break; // Reached the end without success
        }
        
        // Move the second separation until a total match is found
        while(!done && (curProd2 != 3 || curProd3 != 4) && !(begSecond == totalLen - 2 && begThird == totalLen - 1)) {
          curProd3 = removeFirst(curProd3, letters[begThird]);
          curProd2 = op(curProd2, letters[begThird]);
          begThird++;
        }
        
        if(prod1 == 2 && curProd2 == 3 && curProd3 == 4) {
          done = true;
          break;
        }

      }
      
      if (done) {
        out.println("Case #" + cas + ": " + "YES");
      } else {
        out.println("Case #" + cas + ": " + "NO");
      }
    }

    
    out.close();
  }
    
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
