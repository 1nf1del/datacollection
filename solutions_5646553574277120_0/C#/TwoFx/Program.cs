﻿using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;

namespace _151CC
{
    class Program
    {
        private const bool DEBUG = false;
        static void debug()
        {
            Console.WriteLine(solve(new[] { 1, 2, 5 }, 6));
            Console.ReadKey();
        }

        static int solve(int[] coins, int max)
        {
            int[] allv = allValues(coins).ToArray();
            int[] missingV = Enumerable.Range(0, max + 1).Except(allv).ToArray();
            if (missingV.Length == 0)
            {
                return 0;
            }
            int n = 0;
            IEnumerable<IEnumerable<int>> allVals = missingV.Select(missing => allv.Select(value => missing - value).Where(z => z > 0).Except(coins).ToArray()).ToArray();
            while (allVals.Count() > 0)
            {
                IEnumerable<int> av2 = allVals.SelectMany(x => x).Distinct().ToArray();
                int[] occ = av2.Select(x => allVals.Count(y => y.Contains(x))).ToArray();
                var list = av2.Zip(occ, (val, o) => new { val, o }).OrderBy(b => b.o).ToArray();
                n++;
                allVals = allVals.Where(g => !g.Contains(list[0].val));
            }
            return n;
            //foreach (var newc in list)
            //{
            return Enumerable.Range(0, max + 1).Except(coins).Select(t => solve(coins.Concat(new[] { t }).ToArray(), max)).TakeWhile(x => x >= 0).Min() + 1;
            //    if (w == 0)
            //        return 1;
            //    min = w;
            //}
            //return min + 1;
        }

        static string solveCase()
        {
            int[] cdv = readMany<int>();
            int[] dd = readMany<int>();
            return solve(dd, cdv[2]).ToString();
        }

        static IEnumerable<int> allValues(IEnumerable<int> coins)
        {
            if (coins.Count() == 0)
            {
                yield return 0;
                yield break;
            }

            int cv = coins.First();
            IEnumerable<int> n = coins.Skip(1);
            foreach (int v in allValues(n))
            {
                yield return v + cv;
                yield return v;
            }
        }

        static IEnumerable<int> candidates()
        {
            return null;
        }

        static void Main(string[] args)
        {
            if (DEBUG)
            {
                debug();
            }
            else
            {
                Initialize();
                SolveAll(solveCase);
            }
            Console.ReadKey();
        }

        private static StreamReader inf;
        private static StreamWriter outf;

        private delegate void o(string format, params object[] args);
        private static o Output;

        private static T read<T>()
        {
            return (T)Convert.ChangeType(inf.ReadLine(), typeof(T));
        }

        private static string read()
        {
            return inf.ReadLine();
        }

        private static T[] readMany<T>()
        {
            return readMany<T>(' ');
        }

        private static _[] readMany<_>(params char[] ___)
        {
            return read().Split(___).Select(__ => (_)Convert.ChangeType(__, typeof(_))).ToArray();
        }

        private static string[] readMany()
        {
            return readMany<string>();
        }

        private static T[][] readField<T>(int height, Func<char, T> map)
        {
            T[][] res = new T[height][];
            for (int _ = 0; _ < height; _++)
            {
                res[_] = read().Select(c => map(c)).ToArray();
            }
            return res;
        }

        private static char[][] readField(int height)
        {
            return readField(height, c => c);
        }

        private static T[][] readField<T>(int height, Dictionary<char, T> dic)
        {
            return readField(height, c => dic[c]);
        }

        public static void Initialize()
        {
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("Input file: ");
            inf = new StreamReader(Console.ReadLine());
            Console.Write("Output file: ");
            outf = new StreamWriter(Console.ReadLine());
            Console.ForegroundColor = ConsoleColor.White;
            Output = highlightedPrint;
            Output += outf.WriteLine;
        }

        private static void highlightedPrint(string format, params object[] args)
        {
            ConsoleColor prev = Console.ForegroundColor;
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine(format, args);
            Console.ForegroundColor = prev;
        }

        public static void SolveAll(Func<string> calc)
        {
            int cases = int.Parse(inf.ReadLine());
            for (int _ = 1; _ <= cases; _++)
            {
                Output("Case #{0}: {1}", _, calc());
            }
            inf.Close();
            outf.Close();
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("Eureka!");
        }
    }
}