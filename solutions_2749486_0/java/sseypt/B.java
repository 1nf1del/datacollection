package gcj2013.round1c;

import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.BufferedWriter;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

import java.text.NumberFormat;
import java.text.DecimalFormat;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

import java.util.*;

public class B
{
	private static int cc;
	private static void putput() throws IOException
	{
		int cases = INT();
		cc: for (cc = 1; cc<=cases; cc++)
		{
			int X = INT();
			int Y = INT();
			
			int jumpLength = 0;
			int pX = 0;
			int pY = 0;
			String jumps = "";
			
			while ((pX != X || pY != Y) && jumpLength <= 500)
			{
				jumpLength++;
				
				int xAbs = Math.abs(X-pX);
				int yAbs = Math.abs(Y-pY);
				
				if (pX!=X)
				{
					if ((X-pX)>0)
					{
						if (xAbs>=jumpLength)
						{
							pX+=jumpLength;
							jumps += "E";
						}
						else
						{
							pX-=jumpLength;
							jumps += "W";
						}

					}
					else
					{
						if (xAbs>=jumpLength)
						{
							pX-=jumpLength;
							jumps += "W";
						}
						else
						{
							pX+=jumpLength;
							jumps += "E";
						}
					}
				}
				else
				{
					if ((Y-pY)>0)
					{
						if (yAbs>=jumpLength)
						{
							pY+=jumpLength;
							jumps += "N";
						}
						else
						{
							pY-=jumpLength;
							jumps += "S";
						}
					}
					else
					{
						if (yAbs>=jumpLength)
						{
							pY-=jumpLength;
							jumps += "S";
						}
						else
						{
							pY+=jumpLength;
							jumps += "N";
						}
					}
				}
			}

			println("Case #"+cc+": "+jumps);
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		// 11:22 - 
//		String problemFile = "test";
		
		String problemFile = "%s-small-attempt0";
//		String problemFile = "%s-large";
		
		try
		{
			String problem = new Object(){}.getClass().getEnclosingClass().getSimpleName();
			String folder = "_"+new Object(){}.getClass().getPackage().getName();
			
			init(folder+"/"+String.format(problemFile, problem));
			putput(); 
			done();
		}
		catch (Throwable e)
		{
			e.printStackTrace();
			System.exit(1);
		}
	}

	private static File input;
	private static FileReader inputReader;
	private static BufferedReader in;
	private static File output;
	private static FileWriter outputWriter;
	private static BufferedWriter out;
	private static StringTokenizer st;

	private static void init (String fileName) throws IOException
	{
		// input
		input = new File(fileName+".in");
		inputReader = new FileReader(input);
		in = new BufferedReader(inputReader);
		
		// output
		output = new File(fileName+".out");
		outputWriter = new FileWriter(output);
		out = new BufferedWriter(outputWriter);
	}
	
	private static void done ()
	{
		try	{in.close();} catch (Exception e){}
		try	{inputReader.close();} catch (Exception e){}
		try	{out.close();} catch (Exception e){}
		try	{outputWriter.close();} catch (Exception e){}
	}
	
	// in
	private static String LINE() throws IOException
	{
		return in.readLine();
	}
	private static String TOKEN() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
		{
			st = new StringTokenizer(LINE());
		}
		return st.nextToken();
	}
	private static int INT() throws IOException
	{
		return parseInt(TOKEN());
	}
	private static long LONG() throws IOException
	{
		return parseLong(TOKEN());
	}
	private static double DOUBLE() throws IOException
	{
		return parseDouble(TOKEN());
	}
	private static String STRING() throws IOException
	{
		return TOKEN();
	}
	
	// putput
	private static String DOUBLE_STRING(Double d)
	{
		NumberFormat f = NumberFormat.getInstance();
		f.setGroupingUsed(false);
		return f.format(d);
	}
	private static DecimalFormat _DF = new DecimalFormat("0000");
	private static String DF(int i)
	{
		return _DF.format(i);
	}
	
	// out
	private static void print (String str) throws IOException
	{
		out.write(str);
		debug(str,true);
	}
	private static void println (String str) throws IOException
	{
		print(str+"\r\n");
	}
	private static void debug (String str, boolean force) throws IOException
	{
		if (debugCC==0 || cc==debugCC || force)
			System.out.print(str);
	}
	private static void debug (String str) throws IOException
	{
		if (debugCC==0 || cc==debugCC)
			System.out.print(str);
	}
	private static void debugln (String str) throws IOException
	{
		debug(str+"\r\n");
	}
	private static int debugCC = 0;
}
