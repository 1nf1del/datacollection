﻿namespace Codejam
{
    using System;
    using System.Collections.Generic;
    using System.Globalization;
    using System.IO;
    using System.Linq;
    using System.Text;
    using System.Text.RegularExpressions;

    class Program
    {
        private static NumberFormatInfo ni;

        static int Main(string[] args)
        {
            ni = (NumberFormatInfo)CultureInfo.CurrentCulture.NumberFormat.Clone();
            ni.NumberGroupSeparator = String.Empty;

            StreamWriter writer = null;
            if (args.Length < 2) { return 1; }

            try
            {
                // Attempt to open output file.
                writer = new StreamWriter(args[1]);
                // Redirect standard output from the console to the output file.
                Console.SetOut(writer);
                // Redirect standard input from the console to the input file.
                Console.SetIn(new StreamReader(args[0]));
            }
            catch (IOException e)
            {
                TextWriter errorWriter = Console.Error;
                errorWriter.WriteLine(e.Message);
                return 1;
            }

            Solve();

            writer.Close();
            // Recover the standard output stream so that a  
            // completion message can be displayed.
            StreamWriter standardOutput = new StreamWriter(Console.OpenStandardOutput());
            standardOutput.AutoFlush = true;
            Console.SetOut(standardOutput);
            Console.WriteLine("Complete");
            return 0;
        }

        public static List<T> ReadLine<T>()
        {
            return Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                        .Select(s => (T)Convert.ChangeType(s, typeof(T))).ToList();
        }

        public static void Solve()
        {
            int T = int.Parse(Console.ReadLine());

            for (int t = 1; t <= T; t++)
            {
                int N = Convert.ToInt32(Console.ReadLine());
                var heights = new HashSet<int>();

                for (int n = 0; n < 2 * N - 1; n++)
                {
                    var row = ReadLine<int>();
                    foreach(int height in row)
                    {
                        if (!heights.Add(height))
                        {
                            heights.Remove(height);
                        }
                    }
                }

                Console.WriteLine("Case #{0}: {1}", t, string.Join(" ", heights.OrderBy(h => h)));
            }
        }

        //public static void BruteForce(IEnumerable<T> )
    }
}
