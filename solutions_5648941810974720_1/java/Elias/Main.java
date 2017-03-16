import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

// A
public class Main {
	public static void main(String[] args) throws IOException {
		new Main();
	}
	
	public Main() throws IOException {
		//Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner(new File("A-large.in"));
		PrintWriter out = new PrintWriter(new File("A-large.out"));
		
		int amountOfTasks = sc.nextInt();
		for (int task = 1; task <= amountOfTasks; task++) {
			String word = sc.next();
			int[] array = new int[26];
			int[] counts = new int[10];
			for (int i = 0; i < word.length(); i++) {
				char c = word.charAt(i);
				array[c-'A']++;
			}
			//ZERO
			int amount = array['Z'-'A'];
			counts[0] = amount;
			array['Z'-'A'] -= amount;
			array['E'-'A'] -= amount;
			array['R'-'A'] -= amount;
			array['O'-'A'] -= amount;
			
			//TWO
			amount = array['W'-'A'];
			counts[2] = amount;
			array['T'-'A'] -= amount;
			array['W'-'A'] -= amount;
			array['O'-'A'] -= amount;
			
			//SIX
			amount = array['X'-'A'];
			counts[6] = amount;
			array['S'-'A'] -= amount;
			array['I'-'A'] -= amount;
			array['X'-'A'] -= amount;
			
			//EIGHT
			amount = array['G'-'A'];
			counts[8] = amount;
			array['E'-'A'] -= amount;
			array['I'-'A'] -= amount;
			array['G'-'A'] -= amount;
			array['H'-'A'] -= amount;
			array['T'-'A'] -= amount;
			
			//THREE
			amount = array['H'-'A'];
			counts[3] = amount;
			array['T'-'A'] -= amount;
			array['H'-'A'] -= amount;
			array['R'-'A'] -= amount;
			array['E'-'A'] -= amount;
			array['E'-'A'] -= amount;
			
			//FOUR
			amount = array['R'-'A'];
			counts[4] = amount;
			array['F'-'A'] -= amount;
			array['O'-'A'] -= amount;
			array['U'-'A'] -= amount;
			array['R'-'A'] -= amount;

			//FIVE
			amount = array['F'-'A'];
			counts[5] = amount;
			array['F'-'A'] -= amount;
			array['I'-'A'] -= amount;
			array['V'-'A'] -= amount;
			array['E'-'A'] -= amount;
			
			//SEVEN
			amount = array['S'-'A'];
			counts[7] = amount;
			array['S'-'A'] -= amount;
			array['E'-'A'] -= amount;
			array['V'-'A'] -= amount;
			array['E'-'A'] -= amount;
			array['N'-'A'] -= amount;
			
			//ONE
			amount = array['O'-'A'];
			counts[1] = amount;
			array['O'-'A'] -= amount;
			array['N'-'A'] -= amount;
			array['E'-'A'] -= amount;
			
			//NINE
			amount = array['I'-'A'];
			counts[9] = amount;
			array['N'-'A'] -= amount;
			array['I'-'A'] -= amount;
			array['N'-'A'] -= amount;
			array['E'-'A'] -= amount;
			
			String sol = "";
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < counts[i]; j++) {
					sol += i;
				}
			}
			
			String solution = "Case #" + task + ": " + sol;
			System.out.println(solution);
			out.println(solution);
		}
		
		out.close();
		sc.close();
	}
}