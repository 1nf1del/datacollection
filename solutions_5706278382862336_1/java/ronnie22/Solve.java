package a;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Solve 
{
	private static Scanner s;
	private static PrintWriter print;
	
	public static void main(String[] args) throws Exception
	{
		s = new Scanner(new File("input.in"));
		print = new PrintWriter(new File("output.out"));
		
		int n_case = s.nextInt();
		s.nextLine();
		
		for(int i =0;i<n_case;i++)
		{
			long p,q,mcd;
			String line = s. nextLine();
			int posSlash = line.indexOf('/');
			p=Long.parseLong(line.substring(0, posSlash));
			q=Long.parseLong(line.substring(posSlash+1, line.length()));
			mcd = MCD(p,q);
			p = p/mcd;
			q = q/mcd;
			
			long ris = -1;
			long ausq=q;
			while(ausq!=0)
			{
				ausq=ausq/2;
				ris++;
			}
			
			if(q!=Math.pow(2, ris))
			{
				print.println("Case #"+(i+1)+": impossible");
			}
			else
			{
				long ausp = 1;
				while(p >= ausp)
				{
					ris--;
					ausp *= 2; 
				}
				print.println("Case #"+(i+1)+": "+(ris+1));
			}
		}
		print.close();
	}
	
	public static long MCD(long a,long b)
	{
		//a sempre minore di b
		long t;
		while(a!=0)
		{
			t=a;
			a=b % a;
			b=t;
		}
		return b;
	}

}
