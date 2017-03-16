import java.io.*;
import java.util.*;
import java.math.*;

public class A
{

	public static void main(String[] args) throws Exception
	{
    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());
		

		for (int i=1; i<=T; i++)
		{
		  String line=in.readLine();
		  String[] temp=line.split("[ ]+");
		  int N=Integer.parseInt(temp[0]);
		  int L=Integer.parseInt(temp[1]);
		  line=in.readLine();
		  temp=line.split("[ ]+");
		  boolean[][] start=new boolean[N][L];
		  for (int m=0; m<N; m++)
		    for (int k=0; k<L; k++)
		      start[m][k]=(temp[m].charAt(k)=='1');
		  line=in.readLine();
		  temp=line.split("[ ]+");
		  boolean[][] end=new boolean[N][L];
		  for (int m=0; m<N; m++)
		    for (int k=0; k<L; k++)
		      end[m][k]=(temp[m].charAt(k)=='1');	      		    

      String ans=solve(N,L,start,end);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	

	public static String solve(int N, int L, boolean[][] start, boolean[][] end)
  {
    int[] ind=new int[N];
    for (int i=0; i<N; i++) ind[i]=i;
    
    int min=Integer.MAX_VALUE;
 
loop:    
    do
    {
      int[] diff=new int[L];    
      for (int i=0; i<N; i++)
        for (int k=0; k<L; k++)
          if (start[i][k]!=end[ind[i]][k]) diff[k]++;
          
      int count=0;
      for (int k=0; k<L; k++)
      {
        if (diff[k]>0)
        {
          count++;
          if (diff[k]!=N) continue loop;
        }
      }
      
      min=Math.min(min,count);
    }
    while(nextPermutation(ind));
    
    if (min==Integer.MAX_VALUE) return "NOT POSSIBLE";
    
    return ""+min;
  }
  
  
	//elements in a have to be sorted in ascending order
}