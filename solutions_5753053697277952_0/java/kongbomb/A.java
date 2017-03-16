import org.psjava.ds.heap.BinaryHeapFactory;
import org.psjava.ds.heap.Heap;
import org.psjava.util.Pair;
import org.psjava.util.SeriesComparator;
import org.psjava.util.ZeroTo;

import java.io.*;
import java.util.Comparator;
import java.util.Scanner;

public class A implements Runnable {

    @Override
    public void run() {
        Scanner in = new Scanner(System.in);
        for (int casei : ZeroTo.get(in.nextInt())) {
            Heap<Pair<Integer, Integer>> heap = BinaryHeapFactory.getInstance().create(SeriesComparator.create(new Comparator<Pair<Integer, Integer>>() {
                @Override
                public int compare(Pair<Integer, Integer> o1, Pair<Integer, Integer> o2) {
                    return -o1.v2.compareTo(o2.v2);
                }
            }, new Comparator<Pair<Integer, Integer>>() {
                @Override
                public int compare(Pair<Integer, Integer> o1, Pair<Integer, Integer> o2) {
                    return o1.v1.compareTo(o2.v1);
                }
            }));

            int n = in.nextInt();
            int sum = 0;
            for (int i : ZeroTo.get(n)) {
                int p = in.nextInt();
                heap.insert(Pair.create(i, p));
                sum += p;
            }

            System.out.print("Case #" + (casei + 1) + ":");
            int remain = sum;
            while (remain > 0) {
                Pair<Integer, Integer> pair1 = heap.extractMinimum();
                heap.insert(Pair.create(pair1.v1, pair1.v2 - 1));
                remain--;

                String r = (char) (pair1.v1 + 'A') + "";
                if (heap.getMinimum().v2 > remain / 2) {
                    Pair<Integer, Integer> pair2 = heap.extractMinimum();
                    heap.insert(Pair.create(pair2.v1, pair2.v2 - 1));
                    remain--;
                    r += (char) (pair2.v1 + 'A');
                }
                System.out.print(" " + r);
            }
            System.out.println();
        }

    }

    public static void main(String[] args) throws Exception {
        System.setIn(new BufferedInputStream(new FileInputStream("/Users/imyoyo/Desktop/A-small-attempt0.in")));
        System.setOut(merge(System.out, new PrintStream("/Users/imyoyo/kb/mavens/solutions/src/main/java/output.txt")));
        new A().run();
    }

    private static PrintStream merge(final PrintStream p1, final PrintStream p2) {
        return new PrintStream(new OutputStream() {
            @Override
            public void write(int b) throws IOException {
                p1.write(b);
                p2.write(b);
            }
        });
    }

}
