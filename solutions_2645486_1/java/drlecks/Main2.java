package com.powdercode.codejam.round1;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class Main2 {

	private int caser = 1;
	private int numberOfCases = 0;
	
	long E,R,N;
	long[] v;
	
	public void generateResult()
	{
	  try
	  {
			FileInputStream fstream = new FileInputStream("E://in.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			
			String strLine,strLine2;
			//get the number of cases
			strLine = br.readLine();
			if(strLine!=null) numberOfCases = Integer.parseInt(strLine.trim());
	
			
			
			for(int i=0;i<numberOfCases;i++)
			{
				
				strLine2 = br.readLine();
				String[] line = strLine2.trim().split(" ");
				E = Long.parseLong(line[0]);
				R = Long.parseLong(line[1]);
				N = Long.parseLong(line[2]);
				v = new long[(int) N];
				
				strLine2 = br.readLine();
				line = strLine2.trim().split(" ");
				for(int j=0;j<N;j++) v[j] = Long.parseLong(line[j]);
				
				long res = operate();
				
				
				String text = "Case #"+caser+": "+res;
					
				System.out.println (text);
				
				caser++;
			}
			in.close();
		
		} catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
			e.printStackTrace();
		}
	} // end of 
	

	public long operate()
	{
		int maxPos = 0;
		long maxE = E;
		long gain = 0;
		
		maxPos = getNextMax(0);
		for(int i=0;i<N;i++)
		{
			long spentEnergy = 0;

			if(i==maxPos)
			{
				spentEnergy = E;
				if(i<N-1) maxPos = getNextMax(i+1);
			}
			else{
				
				int pity = getNextSmaller(i);
				
				if(pity>0)
				{
					spentEnergy = Math.min(E, (pity+1)*R - Math.min((pity+1)*R,maxE-E));
				}
				else if(maxE<=E+R) spentEnergy = Math.min(R, Math.max(0,R-(maxE-E)) );
			}
			
			
			E-= spentEnergy;
			E+=R;
			if(E>maxE) E = maxE;
			gain += v[i]*spentEnergy;
			
			//System.out.println (spentEnergy+"x"+v[i]+" E:"+E);
		}
		
		return gain;
	}
	
	
	int getNextMax(int ini)
	{
		int maxPos = ini;
		long maxVal = v[ini];
		for(int i=ini;i<N;i++) {
			if(maxVal<v[i]){
				maxPos = i;
				maxVal = v[i];
			}
		}
		
		return maxPos;
	}
	
	int getNextSmaller(int ini)
	{
		long maxVal = v[ini];
		int maxPos = ini+1;
		int nexts =0;
		
		while(maxPos<N &&  v[maxPos]<maxVal)
		{nexts++;maxPos++;}
		
		return nexts;
	}
	
	public static void main(String[] args) 
	{

		Main2 s=new Main2();
		s.generateResult();
	}
	


}