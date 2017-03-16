﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.Round1
{
    class Q1
    {
        static void Main(string[] args)
        {
            int numberOfInputs = Convert.ToInt32(Console.ReadLine());

            for (int i = 1; i <= numberOfInputs; i++ )
            {
                bool impossible = false;
                string fraction = Console.ReadLine();

                string[] terms = fraction.Split('/');
                Int64 p = Convert.ToInt64(terms[0]);
                Int64 q = Convert.ToInt64(terms[1]);

                Int64 factor = gcd(p, q);
                p = p / factor;
                q = q / factor;

                int dp = 0;
                while (p > 1)
                {
                    p = p / 2;
                    dp = dp + 1;
                }
                int dq = 0;
                while (q > 1)
                {
                    if (q % 2 > 0)
                    {
                        impossible = true;
                        break;
                    }
                    q = q / 2;
                    dq = dq + 1;
                }
                if (impossible)
                {
                    Console.WriteLine("Case #" + i + ": impossible");
                    continue;
                }

                Console.WriteLine("Case #" + i + ": " + (dq - dp));                                
            }
        }

        private static Int64 gcd(Int64 p, Int64 q)
        {
            if (q % p == 0) return p;
            return gcd(q % p, p);
        }
    }
}
