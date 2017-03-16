﻿using SolverLib;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemHandler
{
   public class CaseProcessor
   {
      #region Constants

      private const string _STR_FORMAT_CASE_OUTPUT = "Case #{0}: {1}";

      #endregion

      #region Constructor

      public CaseProcessor(ISolver solver)
      {
         _solver = solver;
      }

      #endregion

      #region Properties

      private ISolver _solver;

      public ISolver Solver
      {
         get { return _solver; }
         set { _solver = value; }
      }

      #endregion

      #region Public Methods

      /*
      public virtual void Process(StreamReader inputReader, StreamWriter outputWriter)
      {
         int testCaseCount = int.Parse(inputReader.ReadLine());

         for (int i = 1; i <= testCaseCount; i++)
         {
            string caseInput = inputReader.ReadLine();
            string caseSolution = _solver.Solve(caseInput);
            string caseOutput = string.Format(_STR_FORMAT_CASE_OUTPUT, i, caseSolution);
            outputWriter.WriteLine(caseOutput);
         }
      }
      */

      /// <summary>
      /// Specific to 1C
      /// </summary>
      public virtual void Process(StreamReader inputReader, StreamWriter outputWriter)
      {
         int testCaseCount = int.Parse(inputReader.ReadLine());

         for (int i = 1; i <= testCaseCount; i++)
         {
            string caseInput = inputReader.ReadLine() + '\n' + inputReader.ReadLine();
            string caseSolution = _solver.Solve(caseInput);
            string caseOutput = string.Format(_STR_FORMAT_CASE_OUTPUT, i, caseSolution);
            outputWriter.WriteLine(caseOutput);
         }
      }

      /*
      /// <summary>
      /// Specific processing required for Round 1B (Rank and File)
      /// </summary>
      public virtual void Process(StreamReader inputReader, StreamWriter outputWriter)
      {
         int testCaseCount = int.Parse(inputReader.ReadLine());

         for (int i = 1; i <= testCaseCount; i++)
         {            
            string caseInput = inputReader.ReadLine();
            int caseLineCount = 2 * int.Parse(caseInput) - 1;
            for (int j = 0; j < caseLineCount; j++)
            {
               caseInput += '\n' + inputReader.ReadLine();
            }
            string caseSolution = _solver.Solve(caseInput);
            string caseOutput = string.Format(_STR_FORMAT_CASE_OUTPUT, i, caseSolution);
            outputWriter.WriteLine(caseOutput);
         }
      }
      */

      #endregion
   }
}
