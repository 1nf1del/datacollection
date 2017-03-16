/*
 * Main.java
 * 
 * Created on 13.04.2013, 11:44:12
 * 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam13;

import java.io.*;
import java.math.*;
/**
 *
 * @author Besitzer
 */
public class Main {
    BufferedReader BR;
    BufferedWriter BW;
    
    public void open(String filename)throws IOException{
         File F =  new File(filename);       
         BR = new BufferedReader(new FileReader(F));
         BW= new BufferedWriter(new FileWriter(new File("output.txt")));
    }
    
    public static void quicksort(int[] a) {        
        quicksort(a, 0, a.length - 1);
    }

    // quicksort a[left] to a[right]
    public static void quicksort(int[] a, int left, int right) {
        if (right <= left) return;
        int i = partition(a, left, right);
        quicksort(a, left, i-1);
        quicksort(a, i+1, right);
    }

    // partition a[left] to a[right], assumes left < right
    private static int partition(int[] a, int left, int right) {
        int i = left - 1;
        int j = right;
        int buf;
        while (true) {
            while (a[++i]< a[right]);      // find item on left to swap                                               // a[right] acts as sentinel
            while (a[right]< a[--j])      // find item on right to swap
                if (j == left) break;           // don't go out-of-bounds
            if (i >= j) break;                  // check if pointers cross
            buf=a[i];a[i]=a[j];a[j]=buf;// swap two elements into place
        }
        buf=a[i];a[i]=a[right];a[right]=buf; // swap with partition element
        return i;
    }
    
  
    public void solveA(String filename)throws IOException{
         open(filename);
         int cases =Integer.parseInt(BR.readLine());
         for(int C=0;C<cases;C++){
             String[] S = BR.readLine().split(" ");
             int A =Integer.parseInt(S[0]);
             S = BR.readLine().split(" ");
             int[] M= new int[S.length];
             for(int i=0;i<S.length;i++)M[i]=Integer.parseInt(S[i]);             
             quicksort(M);             
             int Paid =0;boolean goOn=true;
             int CurBest=M.length;
             if(A<=1){goOn=false;}
             for(int i =0;(i<M.length)&&goOn;i++){                 
                 if (Paid+ M.length-i < CurBest) CurBest = Paid+ M.length-i;
                 int  curpay =0;
                 int bufA= A;
                 while (bufA<=M[i]){
                     bufA=2*bufA-1;curpay++;                     
                 }                 
                 if (curpay >=M.length-i)
                    {goOn=false;}
                 else
                     {Paid+=curpay;A=bufA+M[i];
                      if (Paid+M.length-i-1 < CurBest) CurBest = Paid+ M.length-i-1;
                 }                 
             }
             BW.write("Case #"+(C+1)+": "+CurBest+"\n");                          
         }
         System.out.println("Comp succcessful.");
         BR.close();
         BW.close();
    }
    double[][] winProb;
    
     public static BigInteger binomialCoefficient(int n, int r) {
        BigInteger t = BigInteger.ONE;
        
        int m = n-r; // r = Math.max(r, n - r);
        if (r-m<0) {
            r = m;
        }
        
        for (int i = n, j = 1; i > r; i--, j++) {
            t = t.multiply(new BigInteger(""+i)).divide(new BigInteger(""+j));
        }       
        return t;
    }
    
    public void solveB(String filename)throws IOException{
         open(filename);
         int cases =Integer.parseInt(BR.readLine());
         for(int C=0;C<cases;C++){
             String[] S = BR.readLine().split(" ");
             int N= Integer.parseInt(S[0]);
             int X= Integer.parseInt(S[1]);
             int Y= Integer.parseInt(S[2]);
             int R= Math.abs(X)+Math.abs(Y);
             R= R/2;
             double p=-1;
             if (N>= (2*R+1)*(R+1)) p = 1;
             if (N<=(2*R-1)*R) p=0;
             if(p==-1){
                 //System.out.println("Entered case:"+(C+1));
                 if(X==0){p=0;}
                 if(p==-1){
                     int D= N-(2*R-1)*R; //remaining draws
                     int H= Math.abs(Y)+1;
                     //System.out.println("D:"+D+" H:"+H);
                     if (D<H) p=0;
                     if (D>=2*R+H) p=1;
                     if (p==-1) {
                         BigInteger Sum  = BigInteger.ZERO;
                         for(int I =H;I<=D;I++)Sum=Sum.add(binomialCoefficient(D, I));
                         //System.out.println(Sum);
                         //if(H>=30){
                         //    Sum =Sum.divide(new BigInteger("2").pow(D-30));
                         //    p=Sum.doubleValue()/Math.pow(2.0,30.0);
                         //}else{
                             p=Sum.doubleValue()/Math.pow(2.0,D);
                         //}
                     }
                 }
             }
             BW.write("Case #"+(C+1)+": "+p+"\n");                          
         }
         System.out.println("Comp succcessful.");
         BR.close();
         BW.close();
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try{           
           //new Main().solveB("B-small-attempt0.in");
           //new Main().solveA("A-small-attempt2.in");
           new Main().solveB("B-large.in");
        }catch (Exception e){System.err.println(e);}
    }

}
