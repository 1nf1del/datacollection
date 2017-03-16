﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ15.R1A
{
    using System.IO;

    class Program
    {
        public const string PATH_IN = @"D:\Dropbox\Competitions\GCJ15\GCJ14\IN\B-small-attempt1.in";
        public const string PATH_OUT = @"D:\Dropbox\Competitions\GCJ15\GCJ14\OUT\out.txt";


        static void Main(string[] args)
        {
            var s = new B();

            var lines = File.ReadAllLines(PATH_IN);

            var res = s.Solve(lines);

            File.WriteAllLines(PATH_OUT, res);
        }
    }
}
