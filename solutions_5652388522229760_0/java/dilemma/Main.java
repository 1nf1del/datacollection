import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		//Scanner in=new Scanner("in.txt");
		//PrintWriter out=new PrintWriter("out.txt");
		//InputReader in=new InputReader(System.in);
		File file=new File("A-small-attempt1.in");
		PrintWriter out=new PrintWriter("A-small-attempt1.out");
		Scanner in=new Scanner(file);
		
		int pi=in.nextInt();
		for(int qi=1;qi<=pi;qi++){
			int n=in.nextInt();
			BigInteger ans=getAnswer(n);
			if(ans.compareTo(BigInteger.ZERO)==0){
				out.println("Case #"+qi+": INSOMNIA");
			}
			else{
				out.println("Case #"+qi+": "+ans);
			}
		}
		
		out.close();
	}
	
	static BigInteger getAnswer(long n){
		if(n==0){
			return BigInteger.ZERO;
		}
		boolean[] has=new boolean[10];
		BigInteger m=BigInteger.valueOf(n);
		BigInteger nn=BigInteger.valueOf(n);
		int ans=0;
		while(true){
			ans++;
			addNumber(has,m);
			if(check(has)==true){
				return m;
			}
			m=m.add(nn);
		}
	}
	
	static void addNumber(boolean[] has,BigInteger n){
		BigInteger m=new BigInteger(n.toString());
		while(m.compareTo(BigInteger.ZERO)!=0){
			int u=m.mod(BigInteger.TEN).intValue();
			has[u]=true;
			if(check(has)==true){
				return;
			}
			m=m.divide(BigInteger.TEN);
		}
	}
	
	static boolean check(boolean[] has){
		for(int i=0;i<10;i++){
			if(has[i]==false){
				return false;
			}
		}
		return true;
	}
	
	static class InputReader {
		BufferedReader br;
		StringTokenizer st;

		public InputReader (File f){
			try{
				br=new BufferedReader(new FileReader(f));
			}catch(FileNotFoundException e){
				e.printStackTrace();
			}
		}

		public InputReader (InputStream in){
			br=new BufferedReader(new InputStreamReader(in));
		}

		public String next(){
			while(st==null||!st.hasMoreTokens()){
				try{
					st=new StringTokenizer(br.readLine());
				}catch(IOException e){
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		
		public boolean hasNext(){
			while(st==null||!st.hasMoreTokens()){
				String s=null;
				try{
					s=br.readLine();
				}catch(IOException e){
					e.printStackTrace();
				}
				if(s==null)
					return false;
				st=new StringTokenizer(s);
			}
			return true;
		}

		public int nextInt(){
			return Integer.parseInt(next());
		}

		public long nextLong(){
			return Long.parseLong(next());
		}

		public double nextDouble(){
			return Double.parseDouble(next());
		}
	}
}