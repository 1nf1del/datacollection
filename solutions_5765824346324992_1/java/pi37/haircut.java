/*
ID: mkural31
LANG: JAVA
TASK: haircut
*/
import java.io.*;
import java.util.*;

public class haircut{
	public static void main (String [] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("haircut.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("haircut.out")));
		int t = Integer.parseInt(f.readLine());
		int index = 0;
		for(int waka = 0;waka<t;waka++){
			StringTokenizer st = new StringTokenizer(f.readLine());
			int b = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(st.nextToken());
			long m[] = new long[b];
			StringTokenizer sc  = new StringTokenizer(f.readLine());
			//System.out.println(n);
			for(int i = 0;i<b;i++){
				m[i]=Long.parseLong(sc.nextToken());
			//	System.out.println("m[" + i + "] is " + m[i]);
			}
			double huh = (double)0;
			for(int i = 0;i<b;i++){
				huh+=1/((double)m[i]);
			}
			long begin = (long)(((double)n-(double)b)/huh-(double)30);
			long upper = (long)((double)n/huh+(double)30);
			begin=Math.max(begin,0);
			long total = 0;
			for(int i = 0;i<b;i++){
				total +=1+begin/m[i];
			}
			int answer = -1;
			if(n<=total){
				answer=n;
			}
			else{
			ArrayList<Long> sa = new ArrayList<Long>();
			for(int i = 0;i<b;i++){
				long x = 1+begin/m[i];
				while(x*m[i]<upper){
					sa.add(1001*x*m[i]+i);
					x++;
				}
			}
			long so[] = new long[sa.size()];
			index = 0;
			for(long i : sa){
				so[index]=i;
				index++;
			}
			Arrays.sort(so);
			answer = (int)(1+so[(int)n-(int)total-1]%1001);
		/*	while(total<(long)n){
				begin++;
				for(int i = 0;i<b;i++){
					if(begin%m[i]==0){
						total++;
						//System.out.println("Person " + total + " begins at " + begin + " with barber " + (i+1));
						if(total==(long)n){
							answer=(i+1);
							break;
						}
					}
				}
			}*/
		}
			out.print("Case #" + (waka+1) + ": ");
			out.println(answer);
		}
		out.close();
		System.exit(0);
	}
}