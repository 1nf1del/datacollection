package com.google;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * @author Debraj
 */
public final class FairAndSquare {

	/**
	 * @param args
	 */
	public static void main(final String[] args) {
		final List<Long> l = new ArrayList<>();
		l.add(1L);
		l.add(4L);
		l.add(9L);
		//		l.add(121);
		//		l.add(484);

		final Scanner sc = new Scanner(System.in);
		final int t = sc.nextInt();



		/*final int arr[] = {1, 3, 1, 1, 3, 1};
		int j = 0;
		final int aj[] = {1, 2, 3, 4, 5, 0};
		long sr;
		for (long i = 0; i < 100000000000000L; i += arr[j], j = aj[j]) {
			if (isPalindrome(i) && (sr = isPerfectSquare(i)) != 0 && isPalindrome(sr)) {
				System.out.println(i);
			}
		}*/

		/*for (long i = 1; i < 100000000000000L; i++) {
			if (isPalindrome(i) && (sr = isPerfectSquare(i)) != 0 && isPalindrome(sr)) {
				System.out.println(i);
			}
		}*/


		//		System.out.println(allPalindromic(10000000).size());

		long ll;
		for (final Integer n : allPalindromic(10000000)) {
			if (isPalindrome(ll = (long) n * (long) n)) {
				l.add(ll);
			}
		}
		Collections.sort(l);

		/*	for (final Long lll : l) {
			System.out.println(lll);
		}*/

		long a;
		long b;
		int c;

		for (int i = 0; i < t;) {
			a = sc.nextLong();
			b = sc.nextLong();
			c = 0;
			for (final Long n : l) {
				if (a > n) {
					continue;
				}
				if (b < n) {
					break;
				}
				c++;
				/*if (n >= a && n <= b) {
					c++;
				}*/
			}


			System.out.println("Case #" + ++i + ": " + c);

		}
	}

	@SuppressWarnings("boxing")
	public static List<Integer> allPalindromic(final int limit) {
		final List<Integer> result = new ArrayList<>();

		boolean cont = true;
		StringBuilder rev;
		//		int m;
		//		boolean b;
		for (int i = 1; cont; i++) {
			rev = new StringBuilder("" + i).reverse();
			cont = false;
			//			b = false;
			for (final String d : "0123456789".split("")) {
				//				if (!b && (i == 2 * (m = (int) Math.pow(10, (int) Math.log10(i))) || i == 7 * m)) {
				//					i += 2 * m - 1;
				//					cont = true;
				//					break;
				//				}
				//				b = true;

				final int n = Integer.parseInt("" + i + d + rev);
				if (n <= limit) {
					cont = true;
					result.add(n);
					//					System.out.println(n);
				} else {
					break;
				}
			}
		}

		return result;
	}

	/**
	 * @param n
	 * @return long
	 */
	private static long isPerfectSquare(final long n)	{
		//		switch((int) (n & 0xF)) {
		//		case 0: case 1: case 4: case 9:
		final long tst = (long) Math.sqrt(n);
		return tst * tst == n ? tst : 0;
		//		default:
		//			return 0;
		//	}
	}

	/**
	 * @param num
	 * @return boolean
	 */
	private static boolean isPalindrome(final long num) {
		return new StringBuilder().append(num).reverse().toString().equals(Long.toString(num));
	}
}