
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author bachu
 */
public class slides {
    
    public static void main(String args[]) throws FileNotFoundException{
        Scanner scan = new Scanner(new File("slides.in"));
        PrintWriter writer = new PrintWriter(new File("slides.out"));
        int cases = scan.nextInt();
        
        for (int i = 0; i < cases; i++) {
            int b = scan.nextInt();
            int m = scan.nextInt();
            int maxways = maxways(b);
            if (m > maxways) {
                writer.write(String.format("Case #%d: %s%n", i+1, "IMPOSSIBLE"));
                continue;
            }
            else {
                writer.write(String.format("Case #%d: %s%n", i+1, "POSSIBLE"));
            }
            if (m == maxways) {
                writer.write(stuff(b, 1) + "\n");
            }
            else {
                writer.write(pad0(b-1, Integer.toString(m, 2)) + "0\n");
            }
            for (int j = 1; j < b; j++) {
                writer.write(stuff(b, j+1) + "\n");
            }
        }
        writer.close();
    }

    static int maxways(int num) {
        return (int)Math.pow(2, num - 2);
    }
    
    static String stuff(int len, int num0) {
        String result = "";
        for (int i = 0; i < len; i++) {
            if (i < num0) {
                result = result + "0";
            }
            else {
                result = result + "1";
            }
        }
        return result;
    }
    
    static String pad0(int len, String s) {
        if (s.length() < len) {
            return pad0(len, "0" + s);
        }
        else {
            return s;
        }
    }
}
