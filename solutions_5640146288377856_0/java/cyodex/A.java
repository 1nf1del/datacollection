import java.util.*;
import java.io.*;

public class A {
 
    public static void main(String[] args) throws FileNotFoundException {
        new A().solve();
    }

    public void solve() throws FileNotFoundException{
        //Scanner in = new Scanner(System.in);
        Scanner in = new Scanner(new File("a.in"));
        PrintWriter out = new PrintWriter("a.out");
        int tt = Integer.parseInt(in.nextLine());
        for (int test = 1; test <= tt; test++) {
            int r = in.nextInt();
            int c = in.nextInt();
            int w = in.nextInt();
            int ans = c / w + (w - 1) + (c % w == 0 ? 0 : 1); 
            //System.out.println("Case #" + test + ": " + ans);
            out.println("Case #" + test + ": " + ans);
        }

        out.close();
    }
}