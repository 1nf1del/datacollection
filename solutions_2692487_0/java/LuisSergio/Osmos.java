package round1b;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Osmos {

	public static void main(String[] args) throws IOException {
		final File in = new File("C:\\work\\GoogleCodeJam\\input.txt");
		final File out = new File("C:\\work\\GoogleCodeJam\\output.txt");
		final Scanner sc = new Scanner(in);
		final Writer w = new FileWriter(out);
		final int testCases = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= testCases; i++) {
			final long initialiSize = sc.nextLong();
			final int nmotes = sc.nextInt();
			final List<Long> motes = new ArrayList<>(nmotes);
			for (int j = 0; j < nmotes; j++) {
				motes.add(sc.nextLong());
			}
			// System.err.println(r + " - " + t);
			Collections.sort(motes);
			final long result = solve(initialiSize, motes);
			String resultStr = String.format("Case #%d: %d", i, result);
			System.err.println(resultStr);
			w.write(resultStr);
			w.write("\n");
		}
		sc.close();
		w.close();
	}

	private static long solve(long size, List<Long> list) {
		if(size == 1) {
			return list.size();
		}
		//	System.err.println("solving: " + size + " - " + list);
		// first consume everyone smaller than me
		long count = 0;
		while (!list.isEmpty()) {
			long firstvalue = list.get(0).longValue();
			while (!list.isEmpty() && firstvalue < size) {
				size += firstvalue;
				//count++;
				list.remove(0);
				if (list.isEmpty()) {
					break;
				}
				firstvalue = list.get(0).longValue();
			}
			if (list.isEmpty()) {
				break;
			}
			//System.err.println("solving: " + size + " - " + list);
			final int lastIndex = list.size() - 1;
			final long larger = list.get(lastIndex);
			long newguy = size - 1;

			// pretend to remove last
			// simular retirada do maior
			list.remove(lastIndex);
			long case1 = solve(size, list);
			list.add(larger);
			long result1 = case1 + 1;

			// simular adi��o de um cara
			List<Long> newList = new ArrayList<>(list.size() + 1);
			newList.add(newguy);
			newList.addAll(list);
			long case2 = solve(size, newList);
			long result2 = case2 + 1;
			return Math.min(result1, result2);
		}
		return count;
	}


	private static long solve1(long size, List<Long> list) {
		if(size == 1) {
			return list.size();
		}
		//	System.err.println("solving: " + size + " - " + list);
		// first consume everyone smaller than me
		long count = 0;
		while (!list.isEmpty()) {
			long firstvalue = list.get(0).longValue();
			while (!list.isEmpty() && firstvalue < size) {
				size += firstvalue;
				//count++;
				list.remove(0);
				if (list.isEmpty()) {
					break;
				}
				firstvalue = list.get(0).longValue();
			}
			if (list.isEmpty()) {
				break;
			}
			//System.err.println("solving: " + size + " - " + list);
			int lastIndex = list.size() - 1;
			long larger = list.get(lastIndex);
			// simular retirada do maior
			list.remove(lastIndex);
			long case1 = solve(size, list);
			list.add(larger);
			// simular adi��o de um cara
			long newguy = size - 1;
			List<Long> newList = new ArrayList<>(list.size() + 1);
			newList.add(newguy);
			newList.addAll(list);
			//			Collections.sort(list);
			long case2 = solve(size, newList);
			if (case1 <= case2) { //remove larger is better
				count = count + case2 + 1;
				list.remove(lastIndex);
			} else {
				count = count + case1 + 1;
				list = newList;
			}

		}
		return count;
	}
}
