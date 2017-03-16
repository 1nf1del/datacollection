﻿using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.Linq;

namespace CodeJam
{
    using System.Numerics;

    public class SolverBase
    {
        #region Helper
        public static int[] SAToIA(string[] strSplit)
        {
            int[] nums = new int[strSplit.Length];
            for (int iTemp = 0; iTemp < strSplit.Length; ++iTemp)
            {
                nums[iTemp] = int.Parse(strSplit[iTemp]);
            }

            return nums;
        }

        public static long[] SAToLongA(string[] strSplit)
        {
            long[] nums = new long[strSplit.Length];
            for (int iTemp = 0; iTemp < strSplit.Length; ++iTemp)
            {
                nums[iTemp] = long.Parse(strSplit[iTemp]);
            }

            return nums;
        }

        public static int[] StringToIA(string s, char[] delim)
        {
            string[] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries);
            return SAToIA(strSplit);
        }

        public static int[] StringToIA(string s, char c)
        {
            return StringToIA(s, new char[] { c });
        }

        public static int[] StringToIA(string s)
        {
            return StringToIA(s, new char[] { ' ' });
        }

        public static long[] StringToLongA(string s, char[] delim)
        {
            string[] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries);
            return SAToLongA(strSplit);
        }

        public static long[] StringToLongA(string s, char c)
        {
            return StringToLongA(s, new char[] { c });
        }

        public static long[] StringToLongA(string s)
        {
            return StringToLongA(s, new char[] { ' ' });
        }

        public static string[] StringToSA(string s, char[] delim)
        {
            string[] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries);
            return strSplit;
        }

        public static string[] StringToSA(string s, char c)
        {
            return StringToSA(s, new char[] { c });
        }

        public static string[] StringToSA(string s)
        {
            return StringToSA(s, new char[] { ' ' });
        }
        #endregion Helper

        public const int INF = 1000 * 1000 * 1000;
        public const int OFFSET = 1000;

        protected System.IO.StreamWriter writer;

        public void Wrapping(string input, string output)
        {
            string filename = input;
            writer = new System.IO.StreamWriter(output);
            string[] strAll = System.IO.File.ReadAllText(filename).Split(
                new char[] { '\r', '\n' },
                StringSplitOptions.RemoveEmptyEntries);

            ParseAndSolve(strAll);
            writer.Flush();
        }

        virtual public void ParseAndSolve(string[] strAll)
        {
            throw new NotImplementedException();
        }
    }

    public class Z : SolverBase
    {
        override public void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                sres += Solve(strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(string p)
        {
            throw new NotImplementedException();
        }
    }

    public class A : SolverBase
    {
        override public void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                sres += Solve(strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(string p)
        {
            long n = long.Parse(p);
            if (n == 0)
            {
                return "INSOMNIA";
            }

            bool[] seen = new bool[10];
            long curr = 0;
            while (true)
            {
                curr += n;
                foreach (var c in (curr + ""))
                {
                    seen[c - '0'] = true;
                }

                if (seen.All(a => a))
                {
                    return curr + "";
                }
            }
        }
    }

    public class B : SolverBase
    {
        override public void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                sres += Solve(strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(string p)
        {
            int count = 1;
            for (int i = 1; i < p.Length; ++i)
            {
                if (p[i] != p[i - 1])
                {
                    ++count;
                }
            }

            if (p.Last() == '+')
            {
                --count;
            }

            return count + "";
        }
    }

    public class C : SolverBase
    {
        override public void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                sres += Solve(strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(string p)
        {
            BigInteger aStart = new BigInteger((1 << 7) + 1);
            BigInteger factor = new BigInteger((1 << 8) + 1);
            int need = 50;
            BigInteger limit = new BigInteger(1 << 16);
            HashSet<BigInteger> seen = new HashSet<BigInteger>();
            StringBuilder sb = new StringBuilder();
            sb.AppendLine();

            for (var a = aStart;; a += 2)
            {
                Add(sb, a * factor, factor);
                --need;
                if (need == 0)
                {
                    return sb.ToString();
                }
            }

            throw new Exception("not enough");
        }

        private void Add(StringBuilder sb, BigInteger p, BigInteger a)
        {
            string base2 = string.Empty;
            while (p > 0)
            {
                base2 = (p.IsEven ? "0" : "1") + base2;
                p /= 2;
            }

            string factor2 = string.Empty;
            while (a > 0)
            {
                factor2 = (a.IsEven ? "0" : "1") + factor2;
                a /= 2;
            }

            sb.Append(base2);
            for (int i = 2; i <= 10; ++i)
            {
                sb.Append(" ");
                sb.Append(ToBase(factor2, i));
            }

            sb.AppendLine();
        }

        private string ToBase(string base2, int b)
        {
            BigInteger ans = new BigInteger(0);
            foreach (char c in base2)
            {
                ans *= b;
                ans += c - '0';
            }

            return ans.ToString();
        }
    }

    public class D : SolverBase
    {
        override public void ParseAndSolve(string[] strAll)
        {
            int idx = 0;
            int T = int.Parse(strAll[idx++]);

            for (int i = 1; i <= T; ++i)
            {
                string sres = "Case #" + i + ": ";
                sres += Solve(strAll[idx++]);
                writer.WriteLine(sres);
                Console.WriteLine(sres);
            }
        }

        private string Solve(string p)
        {
            var nums = StringToIA(p);
            var K = nums[0];
            var C = nums[1];
            var S = nums[2];

            if (S * C < K)
            {
                return "IMPOSSIBLE";
            }

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < K; i += C)
            {
                long pos = 0;
                for (int j = 0; j < C; ++j)
                {
                    pos *= K;
                    pos += ((j + i) >= K) ? 0 : (j + i);
                }

                sb.Append(pos + 1);
                sb.Append(" ");
            }

            return sb.ToString().Trim();
        }
    }

    public class RunMain
    {
        static void Main(string[] args)
        {
            string dir = "..\\..\\";

            //new A().Wrapping(dir + "ASample.txt", dir + "out.txt");
            //new A().Wrapping(dir + "A-small-attempt0.in", dir + "out.txt");
            //new A().Wrapping(dir + "A-large.in", dir + "out.txt");

            //new B().Wrapping(dir + "BSample.txt", dir + "out.txt");
            //new B().Wrapping(dir + "B-small-attempt0.in", dir + "out.txt");
            //new B().Wrapping(dir + "B-large.in", dir + "out.txt");

            new C().Wrapping(dir + "CSample.txt", dir + "out.txt");
            //new C().Wrapping(dir + "C-small-attempt0.in", dir + "out.txt");
            //new C().Wrapping(dir + "C-small-attempt2.in", dir + "out.txt");
            //new C().Wrapping(dir + "C-large.in", dir + "out.txt");

            //new D().Wrapping(dir + "DSample.txt", dir + "out.txt");
            //new D().Wrapping(dir + "D-small-attempt0.in", dir + "out.txt");
            //new D().Wrapping(dir + "D-small-attempt1.in", dir + "out.txt");
            //new D().Wrapping(dir + "D-large.in", dir + "out.txt");
        }
    }
}
