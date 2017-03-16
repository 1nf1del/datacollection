import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Date;
import java.util.Scanner;



public class Test {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		long beginTime = new Date().getTime();
		
		parse();
				
		System.out.println("" + (new Date().getTime() - beginTime) + " milliseconds.");
	}

	private static void parse() throws IOException {
		// TODO Auto-generated method stub
		FileInputStream inFile = new FileInputStream("parta//A-small-attempt1.in");
		//FileOutputStream outFile = new FileOutputStream("A-small-practice.out");
		Scanner scanner = new Scanner(inFile);
		BufferedWriter writer = Files.newBufferedWriter(Paths.get("parta//A-small-attempt1.out"), StandardCharsets.UTF_8);
	
		int expAmt = scanner.nextInt();
		for(int expNo=1; expNo<= expAmt; expNo++)
		{
			Experiment exp = new Experiment(scanner.nextLong(), scanner.nextLong());
			//System.out.println("read");
			//System.out.print("Case #"+ expNo +": "+ exp.Solve() +"\n");
			writer.write("Case #"+ expNo +": "+ exp.Solve() +"\n");
		}

		scanner.close();
		inFile.close();
		writer.close();	
	}

}
