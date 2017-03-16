import java.util.*;
import java.awt.*;
import java.io.*;

public class ProblemB
{
    public static void main (String args[])
    {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer a;
	int [] num = new int [2500];
	int [] finalArray;
	int currNum, count;
	try
	{
	    in = new BufferedReader (new FileReader ("B-small-attempt0.in"));
	    out = new PrintWriter (new FileWriter ("out.txt"));
	    int lines = Integer.parseInt(in.readLine());
	    for (int x = 1 ; x <= lines ; x++)
	    {
		int numRow = Integer.parseInt (in.readLine());
		Arrays.fill(num, 0);
		finalArray = new int [numRow];
		for (int y = 1; y <= numRow*2-1; y++)
		{
		    a = new StringTokenizer(in.readLine());
		    for (int z = 0; z < numRow; z++)
		    {
			currNum = Integer.parseInt (a.nextToken());
			num [currNum-1]++;
			System.out.println (currNum);
		    }
		}
		count = 0;
		for (int y = 1; y <= 2500; y++)
		{
		    if ((num[y-1]%2)!=0)
		    {
			finalArray[count] = y;
			count++;
			System.out.println ("number: "+y);
			System.out.println ("count: "+num[y-1]);
		    }
		}
		Arrays.sort(finalArray);
		out.print("Case #"+x+":");
		for (int y = 0; y < numRow; y++)
		    out.print(" "+finalArray[y]);
		out.println();
	    }
	    in.close ();
	    out.close ();
	}


	catch (FileNotFoundException e)
	{
	}


	catch (IOException i)
	{
	}
    }
}
