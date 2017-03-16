import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("input.txt"));
		File write = new File("output.txt");
		FileWriter fWriter = new FileWriter(write);

		int nb = sc.nextInt(); /* useless */
		int n = sc.nextInt();
		int j = sc.nextInt();

		fWriter.write("Case #1: \n");
		for (int i = 0; i < j; i++) {
			String output = "1";
			String right = Integer.toBinaryString(i);
			for (int k = 0; k < (n - 2) - right.length() * 2; k += 2) {
				output += "00";
			}
			for (int k = 0; k < right.length(); k++) {
				if (right.charAt(k) == '1') {
					output += "11";
				} else {
					output += "00";
				}
			}
			output += "1";
			
			fWriter.write(output + " 3 4 5 6 7 8 9 10 11\n");
		}
		fWriter.flush();
		fWriter.close();
		sc.close();
	}
}
