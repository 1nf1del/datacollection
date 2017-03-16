package com.zms.gcj;

import java.io.*;
import java.util.Scanner;

/**
 * Created by zms on 14-5-4.
 */
public class TheRepeater {

    public static void main(String[] args) throws Exception {
        File folder = new File("C:\\Users\\zms\\Downloads");
        File input = new File(folder, "A-large.in");
        File output = new File(folder, "A-large.out");
        int[] cc=new int[200];
        try(BufferedReader reader=new BufferedReader(new InputStreamReader(new FileInputStream(input)))) {
        //try (Scanner scanner = new Scanner(new FileInputStream(input))) {
            try (PrintWriter writer = new PrintWriter(new FileOutputStream(output))) {
                int T = Integer.parseInt(reader.readLine());//scanner.nextInt();
                for (int k = 1; k <= T; k++) {
                    System.out.println(k);
                    int N = Integer.parseInt(reader.readLine());//scanner.nextInt();
                    String[] strs = new String[N];
                    int c3 = -1;
                    int[][] cs = new int[N][];
                    boolean bad = false;
                    int i;
                    out:for (i = 0; i < N; i++) {
                        strs[i] = reader.readLine();//scanner.next();
                        System.out.println(strs[i]);
                        char[] chars = strs[i].toCharArray();
                        int len = chars.length;
                        int c1 = -1;
                        int c2 = 0;
                        if (i == 0) {
                            for (int j = 0; j < len; j++) {
                                if (chars[j] != c1) {
                                    c2++;
                                    if (c2 > 1) {
                                        cc[c2 - 2] = c1;
                                    }
                                    c1 = chars[j];
                                }
                            }
                            cc[c2 - 1] = c1;
                            c3 = c2;
                        }
                        cs[i] = new int[c3];
                        c1 = -1;
                        c2 = 0;
                        try {
                            int c4 = 0;
                            for (int j = 0; j < len; j++) {
                                if (chars[j] != c1) {
                                    c2++;
                                    if (c2 > 1) {
                                        cs[i][c2 - 2] = c4+1;
                                        if(cc[c2-2]!=c1) {
                                            bad=true;
                                            break out;
                                        }
                                    }
                                    c1 = chars[j];
                                    c4 = 0;
                                } else {
                                    c4++;
                                }
                            }
                            cs[i][c2 - 1] = c4+1;
                            if(cc[c2-1]!=c1) {
                                bad=true;
                                break out;
                            }
                        } catch (Throwable t) {
                            bad = true;
                            break;
                        }
                        if (c2 != c3) {
                            bad = true;
                            break;
                        }
                    }
                    for (i++; i < N; i++) {
                        reader.readLine();//scanner.next();
                    }
                    if (bad) {
                        writer.printf("Case #%d: Fegla Won\n", k);
                    } else {
                        int t=0;
                        for(int j=0;j<c3;j++) {
                            int max=-1;
                            int min=1000;
                            for (i = 0; i < N; i++) {
                                if(cs[i][j]>max) {
                                    max=cs[i][j];
                                }
                                if(cs[i][j]<min) {
                                    min=cs[i][j];
                                }
                            }
                            int v=Integer.MAX_VALUE;
                            for(int q=min;q<=max;q++) {
                                int p=0;
                                for (i = 0; i < N; i++) {
                                    p+=Math.abs(q-cs[i][j]);
                                }
                                if(p<v) {
                                    v=p;
                                }
                            }
                            t+=v;
                        }
                        writer.printf("Case #%d: %d\n",k,t);
                    }
                }
            }
        }
    }

}
