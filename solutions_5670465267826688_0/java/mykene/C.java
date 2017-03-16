package prel;

import java.io.*;
import java.util.LinkedList;

/**
 * Created by rubenverboon on 11/04/15.
 */
public class C {

  private static int one = 1;
  private static int i = 2;
  private static int j = 3;
  private static int k = 4;

  public static void main(String[] args) throws IOException {
    BufferedReader sc = new BufferedReader(new FileReader(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/Prel-C.in")));
    PrintWriter pw = new PrintWriter(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/Prel-C.out"));
    C b = new C();
    int c = Integer.parseInt(sc.readLine());
    for (int i = 0; i < c; i++) {
      pw.println("Case #" + (i + 1) + ": " + b.solve(sc));
    }
    pw.close();
    sc.close();
  }


  private String solve(BufferedReader sc) throws IOException {
    LinkedList<Integer> list = new LinkedList<>();
    String[] dingen = sc.readLine().split(" ");
    int t = Integer.parseInt(dingen[0]);
    int l = Integer.parseInt(dingen[1]);
    for (int teller = 0; teller < t; teller++) {
      list.add((sc.read() - 'g'));
    }
    sc.readLine();
    boolean foundI = false;
    boolean foundJ = false;
    boolean neg = false;
    int res = one;
    for (int teller = 0; teller < l; teller++) {
      for (int a : list) {
        int c = mult(res, a);
        neg ^= c < 0;
        res = Math.abs(c);
        if (!neg && !foundI && res == i) {
          foundI = true;
          res = one;
        } else if (!neg && !foundJ && foundI && res == j) {
          foundJ = true;
          res = one;
        }
      }
    }
    if(foundI&&foundJ&&!neg&&res==k) return "YES";
    else return "NO";

  }

  private int mult(int a, int b) {
    if (a == one) return b;
    if (b == one) return a;
    if (a == b) return -1;
    if (a == i) return (b == j) ? k : -3;
    if (a == j) return (b == i) ? -4 : i;
    if (a == k) return (b == i) ? j : -2;
    System.out.println(a+ " "+b);
    return -111111;
  }


}
