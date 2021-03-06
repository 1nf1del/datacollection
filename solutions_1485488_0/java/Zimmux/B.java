import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

//javac B.java && java B x.in x.out
public class B {
	public static void main(String[] args) throws FileNotFoundException {
		InputStream in = System.in;
		if(args.length>0)
			in = new FileInputStream(args[0]);
		PrintStream out = System.out;
		if(args.length>1)
			out = new PrintStream(args[1]);

		Solver s = new Solver(new Scanner(in),out);
		//Multiple case input
		s.cases();
		//Single case input
		//s.go();
	}
}

class Solver {
	Scanner in;
	PrintStream out;
	public Solver(Scanner scanner, PrintStream printStream) {
		in = scanner;
		out = printStream;
	}

	public void cases() {
		int numCases = in.nextInt();
		in.nextLine();
		for(int i=0;i<numCases;i++) {
			out.print("Case #"+(i+1)+": ");
			go();
		}
	}
	
	int H,N,M;//H = max water level
	int[][] C;//ceiling height
	int[][] F;//floor height
	double T[][];//time to arrive
	
	public void go() {
		input();
		fill(0,0,0);
		out.println(T[N-1][M-1]);
	}

	private void fill(int x, int y, double t) {
		if(C[x][y]-F[x][y]<50)//not reachable
			return;
		if(T[x][y]<=t)//path not useful
			return;
		T[x][y]=t;
		goTo(x, y, x + 1, y, t);
		goTo(x, y, x, y + 1, t);
		goTo(x, y, x - 1, y, t);
		goTo(x, y, x, y - 1, t);
	}

	private void goTo(int x, int y, int x2, int y2, double t) {
		if(x2<0||x2>=N||y2<0||y2>=M)
			return;
		if(C[x2][y2]-F[x][y]<50)
			return;
		if(C[x][y]-F[x2][y2]<50)
			return;
		//C[x2][y2]-(H-10*t)>=50
		t = Math.max(t,(50+H-C[x2][y2])/10.0);
		if(t>0) {
			if(H-10*t-F[x][y]<20)
				t+=10;
			else
				t+=1;
		}
		fill(x2,y2,t);
	}

	private void input() {
		H = in.nextInt();
		N = in.nextInt();
		M = in.nextInt();

		C = new int[N][M];
		F = new int[N][M];
		T = new double[N][M];

		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				C[i][j]=in.nextInt();

		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				F[i][j]=in.nextInt();

		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				T[i][j]=Double.POSITIVE_INFINITY;
	}
}