import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.Scanner;

public class A {

	Scanner in;
	//BufferedReader in;
	BufferedWriter out ;
	
	public A() throws IOException {
		in = new Scanner(new File("C:\\Bhavin\\workspace\\Test\\src\\prob.in"));
		//in = new BufferedReader(new FileReader("C:\\Bhavin\\workspace\\Test\\src\\prob.in"));

		out = new BufferedWriter(new FileWriter("C:\\Bhavin\\workspace\\Test\\src\\prob.out"));
	}
	public void solve() throws IOException{
		
		int numCases = in.nextInt();
		//int numCases = Integer.parseInt(in.readLine());
		
		for (int i = 1; i <= numCases; i++) {
			runCase(i);
		}
		out.close();in.close();
	}
	private void runCase(int caseNum) throws IOException {
		
		Integer motSize=in.nextInt();
		
		int numMots=in.nextInt();
		
		ArrayList<Integer> mots = new ArrayList<Integer>();
		
		for(int j=1; j<=numMots; j++) {
			mots.add(in.nextInt());
			//createContainer(chests,in, j);
		}
		
		Collections.sort(mots);
		ArrayList<Integer> possibleResults = new ArrayList<Integer>();
		motSize = eatall(mots, motSize);
		
		//if(mots.size()==0) {
			possibleResults.add(mots.size());
		//}
		int countByAdding = 0;
		while(mots.size() > 0) {
			
			int nextmot = mots.get(0);
			
			while(true) {
				countByAdding ++;
				
				motSize = motSize*2-1;
				
				if(motSize > nextmot) {
					break;
				}
				
				if(countByAdding > numMots) 
					break;
			}

			

			motSize = eatall(mots, motSize);
			possibleResults.add(countByAdding + mots.size());
			
			if(countByAdding > numMots) 
				break;
			
		}
		//result = "";
		keysOut=new ArrayList<Integer>();
		ArrayList<Container> chests = new ArrayList<Container>();
		
		int possibleres=999999999;
		Collections.sort(possibleResults);

			
		output(out, caseNum, possibleResults.get(0));
		
	}
	
	private Integer eatall(ArrayList<Integer> mots, Integer motSize) {
		
		ArrayList<Integer> torem = new  ArrayList<Integer>();
		
		for(Integer item:mots) {
			if(item.compareTo(motSize) < 0) {
				motSize = motSize + item;
				torem.add(item);
			} else {
				break;
			}
		}

		mots.removeAll(torem);
		return motSize;
	}

	ArrayList<Integer> keysOut;
	int stars =0;
	int levplayed=0;
	String result;

	class Container implements Comparable<Container> {
		ArrayList keys;
		boolean opened;
		Integer order;
		int key;
		Integer sameKeyCount;

		public Container(int ord, int pkey) {
			order=ord;
			opened=false;
			key=pkey;
			sameKeyCount=0;
			keys=new ArrayList();
			
			
		}

		@Override
		public int compareTo(Container o) {
			
			if(key==o.key) {
				
				if(Collections.frequency(keysOut, key) > 1) {
					return o.order.compareTo(order);
				}
				
				if(sameKeyCount > 0 && o.sameKeyCount > 0) {
					return o.order.compareTo(order);
				}
				if(sameKeyCount.equals(o.sameKeyCount)) {
					return o.order.compareTo(order);
				} else {
					return sameKeyCount.compareTo(o.sameKeyCount);
				}
			} else {
				return o.order.compareTo(order);
			}
				
		}
	}
	
	private void openChest(Container openchest, ArrayList<Integer> keysOut) {
		openchest.opened=true;
		keysOut.remove(new Integer(openchest.key));
		keysOut.addAll(openchest.keys);
		result = result  + openchest.order + " ";
		
	}
	private void createContainer(ArrayList<Container> chests, Scanner in, int ord) {
		Container c = new Container(ord, in.nextInt());
		int kcnt = in.nextInt();
		
		for(int j=1; j<=kcnt; j++) {
			int key=in.nextInt();
			if (c.key==key) {
				c.sameKeyCount++;
			}
			c.keys.add(key);
		}
		
		chests.add(c);
	}
	

	public static void main(String[] args) throws IOException{
		A s = new A();
		s.solve();
		
	}
	
	public void output(BufferedWriter out, int caseNum, int string) throws IOException{
		out.write("Case #" + caseNum + ": " + string + "\n");		
	}
	public void output(BufferedWriter out, int caseNum, String string) throws IOException{
		out.write("Case #" + caseNum + ": " + string + "\n");		
	}


}


