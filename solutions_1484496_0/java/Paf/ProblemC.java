import java.io.*;
import java.util.*;

import static java.lang.System.*;

public class ProblemC {


	public class Case {
		int[] integers;

		LinkedHashMap<Long, ArrayList<Set<Integer>>> sums = new LinkedHashMap<Long, ArrayList<Set<Integer>>>();

		public void solve(int caseIndex) {
			Arrays.sort(integers);

			r(0, 0, new LinkedHashSet<Integer>());

			for (ArrayList<Set<Integer>> s : sums.values()) {
				if (s.size() > 1) {
					println("Case #" + (caseIndex + 1) + ":");
					
					printSet(s.get(0));
					println("");
					printSet(s.get(1));
					println("");
					return;
				}
			}

			println("Case #" + (caseIndex + 1) + ": Impossible");
		}

		void printSet(Set<Integer> s) {
			ArrayList<Integer> l = new ArrayList<Integer>(s);
			for (int i = 0; i < l.size(); i++) {
				if (i > 0) print(" ");
				print(""+l.get(i));
			}
		}

		void r(long sum, int i, Set<Integer> s) {
			if (i >= integers.length) {
				addToMultiMapArrayList(sum, new LinkedHashSet<Integer>(s), sums);
			}
			else {
				r(sum, i + 1, s);

				int value = integers[i];
				if (!s.add(value)) throw new RuntimeException();
				r(sum + value, i + 1, s);
				if (!s.remove(value)) throw new RuntimeException();
			}
		}


	}

	public void run() throws Exception {

		BufferedReader r = new BufferedReader(new FileReader("input.txt"));
		int numCases = new InputParser(r.readLine()).readInt();

		for (int caseIndex = 0; caseIndex < numCases; caseIndex++) {
			Case c = new Case();

			InputParser p = new InputParser(r.readLine());

			c.integers = new int[p.readInt()];
			for (int i = 0; i < c.integers.length; i++) {
				c.integers[i] = p.readInt();
			}

			c.solve(caseIndex);
		}

		r.close();
	}

	public static void main(String[] args) throws Exception {
		fileWriter = new PrintWriter(new OutputStreamWriter(new BufferedOutputStream(new FileOutputStream("output.txt"))));
		new ProblemC().run();
		fileWriter.close();
	}

	public static class InputParser {
		String text;
		int pos;

		public InputParser(String text) {
			this.text = text;
		}

		public void skipSpaces() {
			while (pos < text.length()) {
				if (text.charAt(pos) != ' ') break;
				pos++;
			}
		}

		public String readUntil(char expectedChar) {
			StringBuilder b = new StringBuilder();
			while (pos < text.length()) {
				char ch = text.charAt(pos);
				if (ch == expectedChar) break;
				b.append(ch);
				pos++;
			}
			return b.toString();
		}

		public String readToken() {
			skipSpaces();
			return readUntil(' ');
		}

		public int readInt() {
			return Integer.parseInt(readToken());
		}

		public long readLong() {
			return Long.parseLong(readToken());
		}

		public char readChar() {
			char ch = text.charAt(pos);
			pos++;
			return ch;
		}

		public void readExpectedString(String s) {
			for (int i = 0; i < s.length(); i++) {
				char ch = s.charAt(i);
				if (readChar() != ch) throw new RuntimeException("Expected: "+ch);
			}
		}
	}

	public static PrintWriter fileWriter;

	public static void print(String text) {
		fileWriter.print(text);
		System.out.print(text);
	}

	public static void println(String text) {
		fileWriter.println(text);
		System.out.println(text);
	}

	public static <Key, Value> void addToMultiMapArrayList(Key key, Value value, Map<Key, ArrayList<Value>> map) {
		ArrayList<Value> list = map.get(key);
		if (list == null) {
			list = new ArrayList<Value>();
			map.put(key, list);
		}
		list.add(value);
	}

	public static <Key, Value> void addToMultiMapLinkedHashSet(Key key, Value value, Map<Key, LinkedHashSet<Value>> map) {
		LinkedHashSet<Value> list = map.get(key);
		if (list == null) {
			list = new LinkedHashSet<Value>();
			map.put(key, list);
		}
		list.add(value);
	}

	public static <Key, Value> ArrayList<Value> getMultiMapValues(Map<Key, Collection<Value>> map) {
		ArrayList<Value> result = new ArrayList<Value>();
		for (Collection<Value> list : map.values()) {
			result.addAll(list);
		}
		return result;
	}


}
