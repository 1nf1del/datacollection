import sun.security.util.BigInt;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: gangien
 * Date: 4/11/14
 * Time: 11:46 PM
 * To change this template use File | Settings | File Templates.
 */
public class CodeJam {
    public static void main(String [] args) throws Exception {
//        a();
        b();
//        c();
    }

    public static void a() throws Exception {
        String questionName = "A-large";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);

        for(int x = 0; x < count; x++) {
            String s = r.readLine();
            long P = Long.parseLong(s.split("/")[0]);
            long Q = Long.parseLong(s.split("/")[1]);

            out.printf("Case #%d: ", x + 1);
            String answer = "impossible";
            BigInteger gcd = BigInteger.valueOf(P).gcd(BigInteger.valueOf(Q));
            P = P / gcd.longValue();
            Q = Q / gcd.longValue();
            for(long y = 0; y < 40; y++) {
               if(Q == (1L << y)) {
                   for(long z = 0; ; z++) {
                       if((1L << z) > P) {
                           answer = "" + (y - z + 1);
                           break;
                       }
                   }
                   break;
               }
            }


            out.print(answer);
            out.println();
        }
    }

    static public String charSetToString(Set<Character> set) {
        boolean [] v = new boolean[26];
        Arrays.fill(v, false);
        for(char c : set) {
            v[(c - 'a')] = true;
        }
        String r = "";
        for(int x = 0; x < v.length; x++) {
            if(v[x]) {
                r = r + (char)(x + 'a');
            }
        }
        return r;
    }
    public static long findB(char cur, boolean[] strVisited, List<String> l, Set<Character> chars) {
        long ret = 0;
        int count = 0;
        boolean found = false;


        Set<Character> pos = new HashSet<Character>();
        for(int x = 0; x < l.size(); x++) {
            if(strVisited[x]) {
                continue;
            }
            found = true;

            String s = l.get(x);
            for(int y = 0; y < s.length(); y++) {
                char c = s.charAt(y);
                if(c != cur && !chars.contains(c)) {
                    return 0;
                }
            }
            if(s.startsWith("" + cur)) {

                count++;
                boolean isPos = true;
                for(int y = 0; y < s.length(); y++) {
                    if(s.charAt(y) != cur && !chars.contains(s.charAt(y))) {
                        isPos = false;
                    }
                }
                if(isPos) {
                    strVisited[x] = true;
                    for(int y = 0; y < s.length(); y++) {
                        chars.remove(s.charAt(y));
                    }
                    ret += findB(s.charAt(s.length() - 1), strVisited, l, chars) % 1000000007L;
                    for(int y = 0; y < s.length(); y++) {
                        chars.add(s.charAt(y));
                    }
                    chars.remove(cur);
                    strVisited[x] = false;
                }
            }
            pos.add(s.charAt(0));

        }
        if(!found) {
            if(chars.isEmpty()) {
                return 1;
            } else {
                return 0;
            }
        }
        if(count <= 1) {
            for(char c : pos) {
                if(chars.contains(c)) {
                    chars.remove(c);
                    ret += findB(c, strVisited, l, chars) % 1000000007L;
                    chars.add(c);
                }
            }
        }
        ret = ret % 1000000007L;
        return ret;
    }
    public static void b() throws Exception {
        String questionName = "B-small-attempt3";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);

        for(int x = 0; x < count; x++) {
            String answer = null;
            int N = readNumber(r);
            String str = r.readLine();
            String [] con = str.split(" ");
            List<String> l = Arrays.asList(con);
            boolean [] visited = new boolean[26];
            Arrays.fill(visited, false);
            boolean possible = true;
            Set<Character> chars = new HashSet<Character>();
            for(String s : l) {
                Set<Character> v = new HashSet<Character>();
                char last = s.charAt(0);
                v.add(s.charAt(0));
                for(int y = 0; y < s.length(); y++) {
                    if(y > 0) {
                        if(last != s.charAt(y) && v.contains(s.charAt(y))) {
                            possible = false;
                        }
                    }
                    v.add(s.charAt(y));
                    chars.add(s.charAt(y));
                    last = s.charAt(y);
                }
            }
            boolean [] strVisited = new boolean[l.size()];
            Arrays.fill(strVisited, false);
            long tot = 0;
            for(int y = 0; y < 26; y++) {
                char c = (char)(y + 'a');
                if(chars.contains(c)) {
                    chars.remove(c);
                    tot = (tot + findB(c, strVisited, l, chars))  % 1000000007L;
                    chars.add(c);
                }
            }
            answer = "" + tot;
            if(!possible) {
                answer = "0";
            }


            out.printf("Case #%d: ", x + 1);

            out.print(answer);
            out.println();
        }
    }

    public static void c() throws Exception {
        String questionName = "C-small";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
//        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);

        for(int x = 0; x < count; x++) {
        }
    }

    public static String findTargetString(String s) {
        String ret = "" + s.charAt(0);
        char last = s.charAt(0);
        for(int x = 1; x < s.length(); x++) {
            char c = s.charAt(x);
            if(c != last) {
                last = c;
                ret += c;
            }
        }
        return ret;
    }
    public static int findAMoves(List<String> l) {
        boolean found = false;
        String target = findTargetString(l.get(0));
        int min = l.get(0).length();
        int max = min;
        for(int x = 0; x < l.size(); x++) {
            String t = findTargetString(l.get(x));
            if(!t.equals(target)) {
                found = true;
            }
        }
        if(found) {
            return -1;
        }

        int [] index = new int[l.size()];
        Arrays.fill(index, 0);
        int [][] count = new int [l.size()][target.length()];

        for(int x = 0; x < l.size(); x++) {
            count[x][0] = 1;
            String s = l.get(x);
            int i = 0;
            for(int y = 1; y < s.length(); y++) {
                if(s.charAt(y) == s.charAt(y - 1)) {
                    count[x][i]++;
                } else {
                    i++;
                    count[x][i] = 1;
                }
            }
        }

        int moves = 0;
        for(int x = 0; x < target.length(); x++) {
            boolean done = false;

            do {
                int maxI = 0;
                int maxC = 1;
                int minI = 0;
                int minC = 1;
                for(int y = 1; y < l.size(); y++) {
                    if(count[y][x] > count[maxI][x]) {
                        maxI = y;
                        maxC = 1;
                    } else if(count[y][x] == count[maxI][x]) {
                        maxC++;
                    }

                    if(count[y][x] < count[minI][x]) {
                        minI = y;
                        minC = 1;
                    } else if (count[y][x] == count[minI][x]) {
                        minC++;
                    }
                }
                if(maxI == minI ) {
                    done = true;
                } else {
                    int lmax = count[maxI][x];
                    int lmin = count[minI][x];
                    for(int z = 0; z < l.size(); z++) {
                        if(maxC > minC) {
                            if(count[z][x] == lmin) {
                                moves++;
                                count[z][x]++;
                            }
                        } else {
                            if(count[z][x] == lmax) {
                                moves++;
                                count[z][x] --;
                            }
                        }
                    }
                }

            } while(!done);
        }
        return moves;
    }
    public static void r1ba() throws Exception {
        String questionName = "A-large";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);

        for(int x = 0; x < count; x++) {
            int n = readNumber(r);
            List<String> l = new ArrayList<String>();
            for(int y = 0; y < n; y++) {
                String s = r.readLine();
                l.add(s);
            }
            int moves = findAMoves(l);
            out.printf("Case #%d: ", x + 1);
            final String answer;
            if(moves < 0) {
                answer = "Fegla Won";
            } else {
                answer = "" + moves;
            }
            out.print(answer);
            out.println();

        }
    }


    public static int countBits(long l) {
        int count = 0;
        for(long x = 0; x < 64; x++) {
            if((l & (1L << x)) != 0) {
                count ++;
            }
        }
        return count;
    }

    static void findA(long [][] possible, int index, int N, Set<Integer> used, long value, Set<Long> found) {
        if(index == N) {
            found.add(value);
            return;
        }
        for(int x = 0; x < N; x++) {
            if(!used.contains(x)) {
                if(value == Long.MAX_VALUE || possible[index][x] == value) {
                    used.add(x);
                    long v = value;
                    if(value == Long.MAX_VALUE) {
                        v = possible[index][x];
                    }
                    findA(possible, index + 1, N, used, v, found);
                    used.remove(x);
                }
            }
        }

    }
    public static void r1aa() throws Exception {
        String questionName = "A-large";
        BufferedReader r = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
        out = getPrintStream(questionName + ".out");
        int count = readNumber(r);

        for(int x = 0; x < count; x++) {
            int [] tmp = readNumbers(r);
            int N = tmp[0];
            int L = tmp[1];
            long [] flows = readBinaryLongs(r);
            long [] devices = readBinaryLongs(r);
            long [][] possible = new long[N][N];
            for(int y = 0; y < N; y++) {
                for(int z = 0; z < N; z++) {
                    possible[y][z] = flows[y] ^ devices[z];
                }
            }

            Set<Long> found = new HashSet<Long>();
            findA(possible, 0, N, new HashSet<Integer>(), Long.MAX_VALUE, found);
            String result = "NOT POSSIBLE";
            if(found.size() > 0) {
                int min = Integer.MAX_VALUE;
                for(Long l : found) {
                    min = Math.min(min, countBits(l));

                }
                result = "" + min;
            }

            out.printf("Case #%d: ", x + 1);
            out.println(result);

        }
    }



    public static void r1ab() throws Exception {
        String questionName = "B-small";
        BufferedReader reader = getBufferedReader(questionName + ".in");
        PrintStream out = System.out;
//        out = getPrintStream(questionName + ".out");
        int count = readNumber(reader);

        for(int x = 0; x < count; x++) {
        }
    }



    public static double sqrt(double n) {
        if(n >= 0 && n < 1) {
            double lower = n;
            double upper = 1.0d;
            while(lower <= upper) {
                double cur = (upper - lower) / 2 + lower;
                if(cur * cur == n) {
                    return cur;
                } else if(cur * cur < n) {
                    if(lower == cur) {
                        return lower;
                    }
                    lower = cur;

                } else {
                    if(upper == cur) {
                        return upper;
                    }
                    upper = cur;
                }
            }
            return upper;
        }
        return 0.0d;
    }

    public static BufferedReader getBufferedReader(String file) throws Exception {
        return new BufferedReader(new FileReader(file));
    }
    public static int readNumber(BufferedReader reader) throws Exception {
        return Integer.parseInt(reader.readLine());
    }

    public static long readLong(BufferedReader reader) throws Exception {
        return Long.parseLong(reader.readLine());
    }

    public static int [] readNumbers(BufferedReader reader) throws Exception {
        String [] nums = reader.readLine().split(" ");
        int [] ret = new int[nums.length];
        for(int x = 0; x < nums.length; x++) {
            ret[x] = Integer.parseInt(nums[x]);
        }
        return ret;
    }

    public static long [] readLongs(BufferedReader reader) throws Exception {
        String [] nums = reader.readLine().split(" ");
        long [] ret = new long[nums.length];
        for(int x = 0; x < nums.length; x++) {
            ret[x] = Long.parseLong(nums[x]);
        }
        return ret;
    }
    public static double [] readDoubles(BufferedReader reader) throws Exception {
        String line = reader.readLine();
        String [] nums = line.split(" ");
        double [] ret = new double[nums.length];
        for(int x = 0; x < nums.length; x++) {
            ret[x] = Double.parseDouble(nums[x]);
        }
        return ret;
    }

    public static String [] readStrings(BufferedReader reader) throws Exception {
        String line = reader.readLine();
        String [] nums = line.split(" ");
        return nums;
    }

    public static long [] readBinaryLongs(BufferedReader reader) throws Exception {
        String [] line = readStrings(reader);
        long [] nums = new long[line.length];
        for(int x = 0; x < line.length; x++) {
            nums[x] = Long.parseLong(line[x], 2);
        }
        return nums;
    }

    public static void  quala() throws Exception {
        BufferedReader reader = getBufferedReader("A-small-attempt0.in");
        int amt = readNumber(reader);
        for(int x = 0; x < amt; x++) {
            int a1 = readNumber(reader);
            int [][] rows1 = new int[4][];
            for(int y = 0; y < 4; y++) {
                rows1[y] = readNumbers(reader);
            }

            int a2 = readNumber(reader);
            int [][] rows2 = new int[4][];
            for(int y = 0; y < 4; y++) {
                rows2[y] = readNumbers(reader);
            }
            Set<Integer> ans1 = new HashSet<Integer>();
            for(int y = 0; y < rows1[a1-1].length; y++) {
                ans1.add(rows1[a1 - 1][y]);
            }

            Set<Integer> ans2 = new HashSet<Integer>();
            for(int y = 0; y < rows2[a2-1].length; y++) {
                ans2.add(rows2[a2 - 1][y]);
            }

            ans2.retainAll(ans1);
            if(ans2.size() == 1) {
                System.out.printf("Case #%d: %d\n", x + 1,ans2.iterator().next().intValue());
            } else if(ans2.size() < 1) {
                System.out.printf("Case #%d: Volunteer cheated!\n", x + 1);
            } else {
                System.out.printf("Case #%d: Bad magician!\n", x + 1);
            }
        }
    }

    public static PrintStream getPrintStream(String file) throws Exception {
        if(new File(file).exists()) {
            throw new RuntimeException(new File(file).getAbsolutePath() + " Already exists");
        }

        FileOutputStream fos = new FileOutputStream(new File(file), true);
        PrintStream printStream = new PrintStream(fos);
        return printStream;
    }

    public static void  qualb() throws Exception {
        BufferedReader r = getBufferedReader("B-large.in");
        PrintStream out = System.out;
        out = getPrintStream("B.out");
        int amt = readNumber(r);
        for(int x = 0; x < amt; x++) {
            double [] nums = readDoubles(r);

            double C = nums[0];
            double F = nums[1];
            double X = nums[2];
            double rate = 2.0d;
            double timeSpent = 0.0d;
            double cookies = 0.0d;
            double answer = Double.MAX_VALUE;

            do {
                if(timeSpent > answer) {
                    break;
                }
                answer = Math.min(answer, timeSpent + (X / rate));
                timeSpent = timeSpent + (C / rate);
                rate += F;
            } while(true);

            out.printf("Case #%d: ", x + 1);
            out.print(answer);
            out.println();
        }
    }

    public static void quald() throws Exception {
        BufferedReader r = getBufferedReader("D-large.in");
        PrintStream out = System.out;
        out = getPrintStream("D-large.out");
        int amt = readNumber(r);
        for(int x = 0; x < amt; x++) {
            int count = readNumber(r);
            double [] naomi = readDoubles(r);
            double [] ken = readDoubles(r);
            boolean [] naomiUsed = new boolean[ken.length];
            Arrays.fill(naomiUsed, false);
            int scoreDec = 0;
            for(int y = 0; y < count; y++) {
                double cur = ken[y];
                int min = -1;
                int max = -1;
                for(int z = 0; z < count; z++) {
                    if(!naomiUsed[z]) {
                        if(min == -1) {
                            min = z;
                            if(cur < naomi[z]) {
                                max = z;
                            }
                        } else {
                            if(naomi[min] > naomi[z]) {
                                min = z;
                            }
                            if(naomi[z] > cur) {
                                if(max == -1 || naomi[max] > naomi[z]) {
                                    max = z;
                                }
                            }
                        }
                    }
                }
                if(max == -1) {
                    naomiUsed[min] = true;
                } else {
                    scoreDec++;
                    naomiUsed[max] = true;
                }
            }

            boolean [] kenUsed = new boolean[ken.length];
            Arrays.fill(kenUsed, false);
            int scoreOpt = 0;
            for(int y = 0; y < count; y++) {
                double cur = naomi[y];
                int min = -1;
                int max = -1;
                for(int z = 0; z < count; z++) {
                    if(!kenUsed[z]) {
                        if(min == -1) {
                            min = z;
                            if(cur < ken[z]) {
                                max = z;
                            }
                        } else {
                            if(ken[min] > ken[z]) {
                                min = z;
                            }
                            if(ken[z] > cur) {
                                if(max == -1 || ken[max] > ken[z]) {
                                    max = z;
                                }
                            }
                        }
                    }
                }
                if(max == -1) {
                    scoreOpt++;
                    kenUsed[min] = true;
                } else {
                    kenUsed[max] = true;
                }

            }
            out.printf("Case #%d: ", x + 1);
            out.print(scoreDec);
            out.print(" ");
            out.println(scoreOpt);
        }
    }


}
