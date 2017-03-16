// All important imports
 
import java.awt.Point;
import static java.lang.System.in;
import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.math.BigDecimal;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.InputMismatchException;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Stack;
import java.util.Queue;
import java.util.Random;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.Vector;
 
 
/**
 * 
 * @author Mustafa Filmwala
 * Built using Netbeans IDE 8.0.1
 */
 
 
class Main{
        
        
        
        public static void solve(int test) throws IOException
        {
            int x=ni(),r=ni(),l=ni();
            int check=1;
            if(r*l<x || (r*l)%x!=0){}
            else if(x==4)
            {
                if((r>3 && l>2) || (l>3 && r>2))check=0;
                
            }
            else if(x==3)
            {
                if((r>2 && l>1) || (l>2 && r>1))check=0;
                
            }
            else if(x==2)
            {
            if((r>1 || l>1) )check=0;
            
            }
            else check=0;
            if(check==0)out.println("Case #"+test+": "+"GABRIEL");
            else out.println("Case #"+test+": "+"RICHARD");
        }
        
        // -1 --> n
        //  1 --> p
        // -k --> K
        // -j --> J
        // -i --> I
        
       
        
     
         
        // END OF SOLUTION
        // INPUT OUTPUT TEMPLATE
        static String TESTCASES;
        static PrintWriter out;
        static int Space;
	public static void main(String[] args) throws Exception {
                long endTime,startTime=System.currentTimeMillis();
                
                out=new PrintWriter(System.out);
                InputStream myinp=System.in;
                init(myinp);
                
                Space=0;
                
                int test=ni();
                for(int tc=1;tc<=test;tc++)
                    solve(tc); 
                
               
                out.close();
                endTime=System.currentTimeMillis();
               // tprint("Time: "+(endTime-startTime)+"ms");
                  }
        
        
           // Testcases reader from FILE. If file not found, input is taken from console.
        public static void mytestcases()
        {
            try
            {
            TESTCASES=new String(Files.readAllBytes(Paths.get("C:\\tests.txt")));
            }
            catch(Exception e){TESTCASES="";}
        }
        // Just to print time, not to use anywhere else
        public static void tprint(Object ...obj)
        {
            if(TESTCASES.length()!=0)System.err.println(Arrays.deepToString(obj));
        }
        static InputStream is;
        static BufferedReader brr;
        public static void init(InputStream input) {
        is=input;
        brr=new BufferedReader(new InputStreamReader(input));
        }
    	
	
	protected static byte[] inbuf = new byte[1024];
	static int lenbuf = 0, ptrbuf = 0;
	
	protected static int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
        
        protected static String line() throws IOException
        {
            return brr.readLine();
        }
                
	
	
	// extras
	protected static double nd() throws IOException { return Double.parseDouble(ns()); }
	protected static char nc() { return (char)skip(); }
	protected static boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	protected static int skip() { 
            int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; 
        }
        
        
	protected static String ns() throws IOException
	{       
                if(Space==1)return line();
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	protected static char[] nca(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	
	protected static int[] nia(int n) throws IOException
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
        
        protected static int[][] niaindex(int n) throws IOException
        {
                int ea[][]=new int[n][2];
                for(int i=0;i<n;i++)
                {
                    ea[i][0]=ni();
                    ea[i][1]=i;
                }
                return ea;
        }
        
        protected static long[] nla(int n) throws IOException
	{
		long[] a = new long[n];
		for(int i = 0;i < n;i++)a[i] = nl();
		return a;
	}
        
        protected static long[][] nlaindex(int n) throws IOException
        {
                long ea[][]=new long[n][2];
                for(int i=0;i<n;i++)
                {
                    ea[i][0]=ni();
                    ea[i][1]=i;
                }
                return ea;
        }
        
        protected static String[] nsa(int n) throws IOException
	{
		String[] a = new String[n];
		for(int i = 0;i < n;i++)a[i] = ns();
		return a;
	}
        
        protected static double[] nda(int n) throws IOException
	{
		double[] a = new double[n];
		for(int i = 0;i < n;i++)a[i] = nd();
		return a;
	}
	
	protected static int ni() throws IOException
	{       
                if(Space==1)return Integer.parseInt(line());
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
        
	
	protected static long nl() throws IOException
	{       
                if(Space==1)return Long.parseLong(line());
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
        
        
        // Outputs
        public static void pln(){out.println();}
        public static void ps(String s){out.print(s);}
        public static void pi(int s){out.print(s);}
        public static void pl(long s){out.print(s);}
        public static void pd(double s){out.print(s);}
        public static void psp(){out.print(" ");}
        public static void parr(int s[]){out.println(Arrays.toString(s));}
        public static void parr(String s[]){out.println(Arrays.toString(s));}
        public static void parr(long s[]){out.println(Arrays.toString(s));}        
        public static void parr2(int s[][]){for(int i=0;i<s.length;i++)out.println(Arrays.toString(s[i]));}
        public static void parr2(long s[][]){for(int i=0;i<s.length;i++)out.println(Arrays.toString(s[i]));}
        public static void parr2(String s[][]){for(int i=0;i<s.length;i++)out.println(Arrays.toString(s[i]));}
} 