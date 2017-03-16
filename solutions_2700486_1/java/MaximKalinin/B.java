import java.util.Scanner;

public class B {
    static double solve(int X, int Y, int d, int more) {
        int d0 = (Math.abs(X) + Math.abs(Y)) / 2;
        if (d0 < d)
            return 1;
        if (d0 > d || X == 0 || more == 0)
            return 0;
        int req = Y+1;
        int side = 2*d;
        double[][] dp = new double[side+1][side+1];
        for (int x = side; x >= 0; --x) for (int y = side; y >= 0; --y) {
            if (x+y >= more) {
                dp[x][y] = (x >= req ? 1 : 0);
            } else if (x == side) {
                dp[x][y] = dp[x][y+1];
            } else if (y == side) {
                dp[x][y] = dp[x+1][y];
            } else {
                dp[x][y] = (dp[x][y+1] + dp[x+1][y]) / 2;
            }
        }
        return dp[0][0];
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            int N = in.nextInt(), X = in.nextInt(), Y = in.nextInt();
            int n = 1, d = 0;
            while (N >= n) {
                N -= n;
                d++;
                n += 4;
            }
            double res = solve(X, Y, d, N);
            System.out.println("Case #" + t + ": " + res);
        }
    }
}
