﻿    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Linq;
    using System.Globalization;
    using System.Threading;

    namespace AcmSolution
    {
        internal class Program
        {
            private static void Main(string[] args)
            {
                Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
    #if !ACM_HOME
                Do();
    #else
                var tmp = Console.In;
                Console.SetIn(new StreamReader("C/C-large-1.in"));
                Console.SetOut(new StreamWriter("C/C-large-1-OUT.out"));
                CalcA();

                var tests = GetInt();

                for (int i = 1; i <= tests; ++i)
                {
                    W(string.Format("Case #{0}: ", i));
                    Do();

                    if (i != tests) WL("");

                    //WL((i == tests ? "\n" : "") + "Answer:  " + (i > 9 ? " " : "") + GetStr());
                }
                Console.In.Close();
                Console.Out.Close();
                Console.SetIn(tmp);
               // Console.ReadLine();
#endif
            }

            private const long Max = 100000000000239;
            private static List<long> a = new List<long>();

            private static void CalcA()
            {
                a = new List<long>();

                for (long i = 1; i * i <= Max; ++i)
                {
                    if (IsPalindrome(i) && IsPalindrome(i * i))
                        a.Add(i * i);
                }
            }

            private static bool IsPalindrome(long k)
            {
                var s = k.ToString();

                for (int i = 0; i <= s.Length / 2; ++i)
                    if (s[i] != s[s.Length - 1 - i])
                        return false;

                return true;
            }

            private static void Do()
            {
                var t = GetLongs();
                long n = t[0], m = t[1];
                Assert(m < Max);

                W(a.Count(x => n <= x && x <= m));
            }

            #region Utils
            private const double Epsilon = 0.00000001;

            private static string GetStr()
            {
                return Console.ReadLine();
            }

            private static string[] GetStrs()
            {
                return GetStr().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            }

            private static string[] GetStrs(int cnt)
            {
                var s = new string[cnt];
                for (var i = 0; i < cnt; ++i)
                    s[i] = GetStr();
                return s;
            }

            private static int GetInt()
            {
                return int.Parse(GetStr());
            }

            private static void GetInts(out int a, out int b)
            {
                var q = GetInts();
                a = q[0];
                b = q[1];
            }

            private static void GetInts(out int a, out int b, out int c)
            {
                var q = GetInts();
                a = q[0];
                b = q[1];
                c = q[2];
            }

            private static int[] GetInts()
            {
                var s = GetStrs();
                var a = new int[s.Length];
                for (var i = 0; i < s.Length; ++i)
                    a[i] = int.Parse(s[i]);
                return a;
            }

            private static long GetLong()
            {
                return long.Parse(GetStr());
            }

            private static long[] GetLongs()
            {
                return GetStrs().Select(long.Parse).ToArray();
            }

            private static void WriteDouble<T>(T d)
            {
                Console.WriteLine(string.Format("{0:0.000000000}", d).Replace(',', '.'));
            }

            private static void WL<T>(T s)
            {
                Console.WriteLine(s);
            }

            private static void W<T>(T s)
            {
                Console.Write(s);
            }

            private static void Assert(bool b)
            {
                if (!b) throw new Exception();
            }

            private static void Swap<T>(ref T a, ref T b)
            {
                var temp = a;
                a = b;
                b = temp;
            }

            #endregion
        }
    }