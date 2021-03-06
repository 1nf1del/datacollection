﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Apa2014
{
	class Program
	{
		public static long GetGCD(long num1, long num2)
		{
			while (num1 != num2)
			{
				if (num1 > num2)
					num1 = num1 - num2;

				if (num2 > num1)
					num2 = num2 - num1;
			}
			return num1;
		}

		public static bool IsPowerOfTwo(long x)
		{
			if (x < 2) { return false; }
			return (x & (x - 1)) == 0;
		}

		public static int Log2(long x)
		{
			int i = 0;
			while (x > 1)
			{
				i++;
				x /= 2;
			}

			return i;
		}


		static void Main(string[] args)
		{
			var parser = new Parser("c:\\users\\krox\\downloads\\A-small-attempt2.in");


			var cases = parser.Get<int>(int.Parse).Single();
			for (int j = 0; j < cases; j++)
			{
				var inp = parser.ReadLine().Split('/').Select(t => long.Parse(t)).ToArray();
				var P = inp[0];
				var Q = inp[1];
				var GCD= GetGCD(P, Q);
				P = P / GCD;
				Q = Q / GCD;

				if (!(IsPowerOfTwo(Q)))
				{
					parser.Write("impossible");
					continue;
				}

				int g = 1;
				var rp = P;
				var x = Q / 2;

				for (; ; g++)
				{
					if (rp >= x)
					{
						parser.Write(g.ToString());
						break;
					}

					x /= 2;
				}
			}

			parser.Close();
		}


	}

	public class Parser
	{
		StreamReader s;

		StreamWriter w;

		public Parser(string path)
		{
			this.s = new StreamReader(File.Open(path, FileMode.Open));
			this.w = new StreamWriter(File.Open(path + ".res.txt", FileMode.OpenOrCreate));
		}

		public TType GetOne<TType>(Func<string, TType> converter)
		{
			return Get(converter).First();
		}

		public string ReadLine()
		{
			return this.s.ReadLine();
		}

		public IList<TType> Get<TType>(Func<string, TType> converter)
		{
			return this.s
				.ReadLine()
				.Split(' ')
				.Select(t => converter(t))
				.ToList();
		}

		int caseNr = 1;
		public void Write(string res)
		{
			this.w.WriteLine(string.Format(
				"Case #{0}: {1}",
				this.caseNr,
				res));

			caseNr++;
		}

		public void Close()
		{
			this.w.Close();
			this.s.Close();
		}
	}
}
