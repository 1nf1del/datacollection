﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamQualification
{
    class ProblemB
    {
        public void Execute(string[] args)
        {

            Dictionary<int, int> maxNoSurprise = new Dictionary<int, int>();
            Dictionary<int, int> maxSurprise = new Dictionary<int, int>();

            for (int i = 0; i <= 30; i++)
            {
                maxNoSurprise[i] = Math.Min(((i - 1) / 3) + 1, i);
            }

            for (int i = 0; i <= 30; i++)
            {
                maxSurprise[i] = Math.Min(((i + 1) / 3) + 1, i);
            }

            int lines = int.Parse(Console.ReadLine());

            StringBuilder output = new StringBuilder();

            for (int k = 0; k < lines; k++)
            {

                string[] line = Console.ReadLine().Split(' ');
                int dancers = int.Parse(line[0]);
                int surprises = int.Parse(line[1]);
                int bestResult = int.Parse(line[2]);

                int possibleNoSurprise = 0;
                int possibleSurpriseOnly = 0;

                for (int i = 3; i < 3 + dancers; i++)
                {
                    int total = int.Parse(line[i]);

                    if (maxNoSurprise[total] >= bestResult)
                    {
                        possibleNoSurprise++;
                    }
                    else if (maxSurprise[total] >= bestResult)
                    {
                        possibleSurpriseOnly++;
                    }
                }

                int totalPossible = possibleNoSurprise + Math.Min(possibleSurpriseOnly, surprises);
                output.AppendLine("Case #" + (k+1) + ": " + totalPossible);
            }

            Console.WriteLine();
            Console.WriteLine(output.ToString());
        }
    }
}
