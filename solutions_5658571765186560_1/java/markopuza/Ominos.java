import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Ominos {

	public static void main(String[] args) throws IOException {
	BufferedReader in = new  BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(in.readLine());
		
		for (int i = 1; i <= t; i++) {
			String[] next = in.readLine().split(" ");
			int x = Integer.parseInt(next[0]);
			int r = Integer.parseInt(next[1]);
			int c = Integer.parseInt(next[2]);
			boolean result = false;
			
			if (r*c % x != 0) { 
				result = true;
			}
			else {
				if (r == 1 || c == 1) {
					if (x >= 3) {
						result = true;
					}
				}
				else if (r <= 4 && c <= 4) {	
					switch (r*c) {
					case 4:
						if (x >= 4) result = true;
						break;
					case 6:
						if (x >= 6) result = true;
						break;
					case 8: 
						if (x >= 4) result = true;
						break;
					case 9:
						if (x >= 9) result = true;
						break;
					case 12:
						if (x >= 6) result = true;
						break;
					case 16:
						if (x >= 8) result = true;
						break;
					default:
						break;
					}
					
				}
				else if (r == 2 || c == 2) {
					if (x >= 4) result = true;
				}
				else if (r == 3 || c == 3) {
					if (x >= 6) result = true;
				}
				else if (Math.max(r, c) < x) result = true;
				else if (x >= 7) result = true;
				
			}
			if (result) System.out.println("Case #" + i + ": " + "RICHARD");
			else System.out.println("Case #" + i + ": " + "GABRIEL");
		}
	}

}
