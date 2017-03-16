﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace CodeJam2015Round1A
{
    class Program
    {
        private static void Debug()
        {
            // Do debugging here
        }

        private static string SolveCase()
        {
            int[] bn = ReadMany<int>();
            int b = bn[0];
            int n = bn[1];
            int[] barbers = ReadMany<int>();

            int lcm = barbers.Aggregate(1, LCM);
            int customers = barbers.Sum(barber => lcm / barber);

            Console.WriteLine("customers: {0}", customers);

            n %= customers;
            n = n == 0 ? customers : n;

            for (int i = 0; true; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    if (i % barbers[j] == 0)
                    {
                        n--;
                    }
                    if (n == 0)
                    {
                        return (j + 1).ToString();
                    }
                }
            }
            return "Error!";
        }

        private static int GCD(int a, int b)
        {
            while (b > 0)
            {
                int temp = a % b;
                a = b;
                b = temp;
            }
            return a;
        }

        private static int LCM (int a, int b)
        {
            return (a * b) / GCD(a, b);
        }

        public static void Main(string[] args)
        {
            Initialise();
            SolveAllCases(SolveCase);
        }

        private static StreamReader sr;
        private static StreamWriter sw;

        private delegate void Printer(string format, params object[] args);
        private static Printer print;

        private static T Read<T>()
        {
            return (T)Convert.ChangeType(sr.ReadLine(), typeof(T));
        }

        private static string Read()
        {
            return sr.ReadLine();
        }

        private static T[] ReadMany<T>()
        {
            return ReadMany<T>(' ');
        }

        private static T[] ReadMany<T>(params char[] sep)
        {
            return sr.ReadLine().Split(sep).Select(x => (T)Convert.ChangeType(x, typeof(T))).ToArray();
        }

        private static void Initialise()
        {
            Console.Write("Input file: ");
            string path = (Environment.OSVersion.Platform == PlatformID.Unix ||
                           Environment.OSVersion.Platform == PlatformID.MacOSX) ?
                           Environment.GetEnvironmentVariable("HOME") :
                           Environment.ExpandEnvironmentVariables("%HOMEDRIVE%%HOMEPATH%");
            // Change this to your preferences.
            sr = new StreamReader(path + "\\Downloads\\" + Console.ReadLine());
            Console.Write("Output file: ");
            // Change this how you prefer it.
            sw = new StreamWriter(path + "\\Desktop\\codejam\\" + Console.ReadLine());
            print = sw.WriteLine;
            print += ConsolePrint;
        }

        private static void ConsolePrint(string format, params object[] args)
        {
            ConsoleColor prev = Console.ForegroundColor;
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine(format, args);
            Console.ForegroundColor = prev;
        }

        private static void SolveAllCases(Func<string> solve)
        {
            int cases = Read<int>();
            for (int c = 1; c <= cases; c++)
            {
                print("Case #{0}: {1}", c, solve());
            }
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Finished!");

            sr.Close();
            sw.Close();

            Console.ReadKey(true);
        }
    }
}