package com.codejam.firstround2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

import javax.print.attribute.standard.Finishings;

public class Elf {
	static int count = 0;
	static PrintWriter out;
	static String CASE = "Case #";
	static String COLON = ": ";

	public static void main(String[] args) {
		try {
			out = new PrintWriter(new File("d:\\a.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		Scanner scanner = null;
		try {
			scanner = new Scanner(new File("d:\\a.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int n = Integer.parseInt(scanner.nextLine());
		for (int i = 0; i < n; i++) {
			String[] split = scanner.nextLine().split("/");
			int nu = Integer.parseInt(split[0]);
			int dm = Integer.parseInt(split[1]);
			int gcd = gcd(nu, dm);
			count = 0;
			int calculate = calculate(nu / gcd, dm / gcd);
			if (calculate != -1)
				out.println(CASE + (i + 1) + COLON + calculate);
			else
				out.println(CASE + (i + 1) + COLON + IMPOSSIBLE);
		}
		out.flush();
		out.close();

	}

	private static int gcd(int a, int b) {
		if (a == 0 || b == 0)
			return 0;
		while (b > 0) {
			int temp = b;
			b = a % b; // % is remainder
			a = temp;
		}
		return a;
	}

	static String IMPOSSIBLE = "impossible";

	public static int calculate(int num, int dm) {
		count++;
		if (dm % 2 == 1) {
			return -1;
		}
		dm = dm / 2;
		int newNum = num >= dm ? 1 : 0;
		num = num - newNum * dm;
		if (newNum == 1) {
			if (checkIsValid(num, dm)) {
				return count;
			}
			return -1;
		}
		if (num == 0) {
			return 0;
		} else {
			return calculate(num, dm);
		}
	}

	private static boolean checkIsValid(int num, int dm) {

		if ((num == 1 || num == 0) && dm == 1) {
			return true;
		}
		if (dm % 2 == 1) {
			return false;
		}
		dm = dm / 2;
		int newNum = num >= dm ? 1 : 0;
		num = num - newNum * dm;
		return checkIsValid(num, dm);
	}
}
