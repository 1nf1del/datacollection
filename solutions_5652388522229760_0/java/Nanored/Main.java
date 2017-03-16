import java.io.FileReader;
import java.io.IOException;

public class Main {
	
	public static boolean test(boolean[] b) {
		for(boolean bo : b)
			if(!bo) return false;
		return true;
	}

  public static void main(String[] args) {
		try {
			FileReader f = new FileReader(args[0]);
			String s = "";
			int i = 0;
			while((i = f.read()) != 10)
				s += (char)i;
			int t = Integer.valueOf(s);
			s = "";
			for (int j = 1; j <= t; j++) {
				while((i = f.read()) != 10)
					s += (char)i;
				int n = Integer.valueOf(s);
				s = "";
		    	if(n == 0)
		    		System.out.println("Case #" + j + ": INSOMNIA");
		    	else {
		    		boolean[] b = {false, false, false, false, false, false, false, false, false, false};
		    		int z = 0;
		    		do {
		    			z += n;
		    			char[] m = ((Integer) z).toString().toCharArray();
		    			for(char c : m)
		    				b[(int) c - 48] = true;
		    		} while(!test(b));
		        	System.out.println("Case #" + j + ": " + z);
		    	}
		    }
			f.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
  }
 
}