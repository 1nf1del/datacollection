﻿using System;

namespace B
{
    class Program
    {
        static void Main()
        {
            string numTestsString = Console.ReadLine();
            int numTestCases = int.Parse(numTestsString);
            for (int i = 0; i < numTestCases; ++i)
            {
                var solver = new SolverB();
                string output = solver.SolveOne(Console.In);
                Console.WriteLine("Case #{0}: {1}", i + 1, output);
            }
        }
    }
}
