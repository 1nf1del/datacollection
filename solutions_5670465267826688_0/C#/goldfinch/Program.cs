﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ15
{
    using System.IO;

    class Program
    {
        public const string PATH_IN = @"D:\Dropbox\Competitions\GCJ15\GCJ14\IN\C-small-attempt0.in";
        public const string PATH_OUT = @"D:\Dropbox\Competitions\GCJ15\GCJ14\OUT\c-small.out";


        static void Main(string[] args)
        {
            var s = new C();

            var lines = File.ReadAllLines(PATH_IN);

            var res = s.Solve(lines);

            File.WriteAllLines(PATH_OUT, res);
        }
    }
}
