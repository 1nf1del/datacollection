
package urtbest;






import java.awt.Point;
import java.io.*;
import java.io.ObjectInputStream.GetField;
import java.sql.Array;
import java.util.*;
import java.util.jar.Attributes.Name;
import java.util.logging.Level;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

















import javax.print.attribute.HashAttributeSet;
import javax.swing.text.MaskFormatter;
 
 
 
 
 
 
 
 class TestClass {
 
static long mod ;

static ArrayList<Integer>[] maps; 
static long[][] dp;
static int z;
static int[] V;
static long[][] Tree;
static long[][] lazy;
static int[] P;
static int[] A;
static int[] S;
static int nextnode;
static long max;
static boolean important;
static ArrayList<Integer> Final;
static HashMap<Long,Long>[] Why = new HashMap[11];

public static void make_me(int curr , int x , int y, int[] A){
  
      if(x>y) return ;
      
      if(x==y){
        P[curr] =A[x];
        return ;
      }
      make_me(2*curr, x, (x+y)/2, A);
     make_me(2*curr+1, (x+y)/2+1,y, A);
     P[curr] = Math.min(P[2*curr],P[2*curr+1]);
}

public static int get_me(int curr , int l , int r , int x ,int y){
  
     if(l>r || x>r ||l>y) return Integer.MAX_VALUE;
     
     if(x<=l && y>=r) return P[curr];
     
     return Math.min(get_me(2*curr, l, (l+r)/2, x, y),get_me(2*curr+1, (l+r)/2+1, r, x, y));
}

public static void main(String args[] ) throws java.lang.Exception {
 
 
 
//InputStream inputStream = System.in;
//InputReader in = new InputReader(inputStream);
 
//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//BufferedReader in = new BufferedReader(new FileReader("C:\\Users\\Sompathak\\Desktop\\yes.txt"));
//Scanner in = new Scanner(new FileReader("C:\\Users\\Sompathak\\Desktop\\yes.java"));
 PrintWriter pw = new PrintWriter(new FileWriter("C:\\Users\\sompathak\\Desktop\\output.txt"));
//InputStream inputStream = System.in;
//InputReader in = new InputReader(inputStream);
//Scanner in = new Scanner(new InputStreamReader(System.in));
 Scanner in = new Scanner(new FileReader("C:\\Users\\sompathak\\Desktop\\yes.java"));
//we can we will ??? !!!!!! SOM RISES
//long startTime = System.currentTimeMillis();
//long startTime = System.currentTimeMillis();
 
//float endTime   = System.currentTimeMillis();
//float totalTime = (endTime - startTime)/(float)1000;
//System.out.println(totalTime+" sec....."); 
 
// {is, in ,the ,to ,he ,she}
mod=1000000007;
int cases =0;
int t = in.nextInt();
while(t>0){
  t--;
  cases++;
  pw.print("Case #"+cases+": ");
  int n = in.nextInt();
  int[] A = new int[n];
  int sum=0;
  for(int i=0;i<n;i++) A[i]= in.nextInt();
  for(int i=0;i<n;i++) sum+=A[i];
  while(sum!=0){
      int max=0;
      int index =0;
    for(int i=0;i<n;i++)
          if(A[i]>max){
            max = A[i];
            index = i;
          }
    pw.print((char)('A'+index));
    A[index]--;
    sum--;
    max =0;
    index =0;
    for(int i=0;i<n;i++)
        if(A[i]>max){
          max = A[i];
          index = i;
        }
    int  nextmax =0;
    max=0;
    
    for(int i=0;i<n;i++)
        if(A[i]>max && index!=i){
          max = A[i];
          nextmax = i;
        }
    
    if((sum-1)/2>=max){
      A[index]--;
      sum--;
      pw.print((char)('A'+index));
      
    }
    pw.print(" ");
  }
  pw.flush();
  pw.println();
}


}public static class InputReader
{
private InputStream stream;
private byte[] buf = new byte[1024];
private int curChar;
private int numChars;
private SpaceCharFilter filter;
 
public InputReader(InputStream stream)
{
this.stream = stream;
}
 
public int read()
{
if (numChars == -1)
throw new InputMismatchException();
if (curChar >= numChars)
{
curChar = 0;
try
{
numChars = stream.read(buf);
} catch (IOException e)
{
throw new InputMismatchException();
}
if (numChars <= 0)
return -1;
}
return buf[curChar++];
}
 
public int nextInt()
{
int c = read();
while (isSpaceChar(c))
c = read();
int sgn = 1;
if (c == '-')
{
sgn = -1;
c = read();
}
int res = 0;
do
{
if (c < '0' || c > '9')
throw new InputMismatchException();
res *= 10;
res += c - '0';
c = read();
} while (!isSpaceChar(c));
return res * sgn;
}
 
public String readString()
{
int c = read();
while (isSpaceChar(c))
c = read();
StringBuilder res = new StringBuilder();
do
{
res.appendCodePoint(c);
c = read();
} while (!isSpaceChar(c));
return res.toString();
}
public double readDouble() {
int c = read();
while (isSpaceChar(c))
c = read();
int sgn = 1;
if (c == '-') {
sgn = -1;
c = read();
}
double res = 0;
while (!isSpaceChar(c) && c != '.') {
if (c == 'e' || c == 'E')
return res * Math.pow(10, nextInt());
if (c < '0' || c > '9')
throw new InputMismatchException();
res *= 10;
res += c - '0';
c = read();
}
if (c == '.') {
c = read();
double m = 1;
while (!isSpaceChar(c)) {
if (c == 'e' || c == 'E')
return res * Math.pow(10, nextInt());
if (c < '0' || c > '9')
throw new InputMismatchException();
m /= 10;
res += (c - '0') * m;
c = read();
}
}
return res * sgn;
}
public long readLong() {
int c = read();
while (isSpaceChar(c))
c = read();
int sgn = 1;
if (c == '-') {
sgn = -1;
c = read();
}
long res = 0;
do {
if (c < '0' || c > '9')
throw new InputMismatchException();
res *= 10;
res += c - '0';
c = read();
} while (!isSpaceChar(c));
return res * sgn;
}
public boolean isSpaceChar(int c)
{
if (filter != null)
return filter.isSpaceChar(c);
return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
}
 
public String next()
{
return readString();
}
 
public interface SpaceCharFilter
{
public boolean isSpaceChar(int ch);
}
}
}                                       