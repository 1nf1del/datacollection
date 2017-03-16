﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.IO;



namespace GoogleCodeJam_2015
{
    internal class Qualification_StandingOvation
    {
        private const string ModuleName = "Qualification_StandingOvation";
        private static Library.DataSize ModuleDataSize = Library.DataSize.Small;
        private static int _moduleReportingSize = 1;


        public static void Process()
        {
            var input = Library.GetFilePath(Library.DataInputType.Input, ModuleDataSize, ModuleName);

            Console.WriteLine("###> Processing {0} @ {1}", input, DateTime.Now.ToLongTimeString());
            Console.WriteLine();
            var watch = new Stopwatch();
            watch.Start();

            var caseLineCount = 1;
            var lines = Library.GetAllLines(input);
            var totalCount = int.Parse(lines[0]);
            //_moduleReportingSize = totalCount / 10;

            var output = Library.GetFilePath(Library.DataInputType.Output, ModuleDataSize, ModuleName);
            Library.DeleteFile(output);
            //Library.RenameFile(output);

            for (var i = 0; i < totalCount; i++)
            {
                Library.AppendLine(output, ProcessCase(i + 1, lines.Skip(1 + i * caseLineCount).Take(caseLineCount).ToList()));
            }
            Library.WriteToFile(output, Library.GetContents(output).Trim());
            watch.Stop();
            Console.WriteLine("###> Finished @ {0}, processed {1} cases in {2:N1} seconds", DateTime.Now.ToLongTimeString(), totalCount, watch.ElapsedMilliseconds / 1000.0);

            if (Library.HasExpectedResult(ModuleDataSize, ModuleName))
            {
                Console.WriteLine("###> Output is{0} as expected", Library.CompareResultToExpected(ModuleDataSize, ModuleName) ? "" : " NOT");
            }

            Console.WriteLine("Press any key to exit...");
            Console.ReadKey();
        }

        private static string ProcessCase(int id, List<string> parameters)
        {
            if (id % _moduleReportingSize == 0) Console.WriteLine("===> Processing case {0}", id);
            var pars = parameters[0].Split(new[] { ' ' });
            var res = Solution(int.Parse(pars[0]), pars[1].Select(c => int.Parse(c.ToString())).ToArray());

            return String.Format("Case #{0}: {1}", id, res);
        }

        private static int Solution(int maxShy, int[] people)
        {
            var up = people[0];
            var extra = 0;
            for (var shyness = 1; shyness <= maxShy; shyness++)
            {
                if (people[shyness] > 0)
                {
                    if (up < shyness)
                    {
                        var add = shyness - up;
                        extra += add;
                        up += add;
                    }
                    up += people[shyness];
                }
            }
            return extra;
        }

        private class Library
        {
            public enum DataInputType
            {
                Input,
                Output,
                Expected
            };

            public enum DataSize
            {
                Test,
                Small,
                Large
            };

            public static string Folder = @"D:\Projects\GoogleCodeJam\Data";
            public static Hashtable Cache = new Hashtable();

            public static object GetCachedObject(object key)
            {
                return Cache[key];
            }

            public static void SetCachedObject(object key, object value)
            {
                if (!Cache.ContainsKey(key)) Cache.Add(key, value);
            }

            public static string GetFilePath(DataInputType inputType, DataSize dataSize, string module)
            {
                return Path.Combine(Folder,
                    module + "_"
                    + (dataSize == DataSize.Test ? "test" : (dataSize == DataSize.Small ? "small" : "large"))
                    +
                    (inputType == DataInputType.Input
                        ? ".in"
                        : (inputType == DataInputType.Output ? ".out" : ".expected")));
            }

            public static List<string> GetAllLines(DataSize dataType, string module)
            {
                return GetAllLines(GetFilePath(DataInputType.Input, dataType, module));
            }

            public static List<string> GetAllLines(string inputFile)
            {
                var reader = new StreamReader(inputFile);
                var result = new List<string>();
                try
                {
                    while (!reader.EndOfStream)
                        result.Add(reader.ReadLine());
                }
                finally
                {
                    reader.Close();
                }
                return result;
            }

            public static IEnumerable<string> GetLines(DataSize dataSize, string module)
            {
                return GetLines(GetFilePath(DataInputType.Input, dataSize, module));
            }

            public static IEnumerable<string> GetLines(string inputFile)
            {
                var reader = new StreamReader(inputFile);
                try
                {
                    while (!reader.EndOfStream)
                        yield return reader.ReadLine();
                }
                finally
                {
                    reader.Close();
                }
            }

            public static string GetContents(DataInputType inputType, DataSize dataSize, string module)
            {
                return GetContents(GetFilePath(inputType, dataSize, module));
            }

            public static string GetContents(string inputFile)
            {
                var reader = new StreamReader(inputFile);
                try
                {
                    return reader.ReadToEnd();
                }
                finally
                {
                    reader.Close();
                }
            }

            /// <summary>
            /// Return a stream of List of strings of size lineCount although the last List returned may have lessa than lineCount elements
            /// </summary>
            public static IEnumerable<List<string>> GetLines(DataSize dataSize, string module, int lineCount)
            {
                return GetLines(GetFilePath(DataInputType.Input, dataSize, module), lineCount);
            }

            public static IEnumerable<List<string>> GetLines(string inputFile, int lineCount)
            {
                var reader = new StreamReader(inputFile);
                try
                {
                    var lines = new List<string>(lineCount);
                    while (!reader.EndOfStream)
                    {
                        lines.Add(reader.ReadLine());
                        if (lines.Count == lineCount)
                        {
                            yield return lines;
                            lines = new List<string>(lineCount);
                        }
                    }
                    if (lines.Count > 0) yield return lines;
                }
                finally
                {
                    reader.Close();
                }
            }

            public static void AppendLine(DataSize dataSize, string module, string line)
            {
                AppendLine(GetFilePath(DataInputType.Output, dataSize, module), line);

            }

            public static void AppendLine(string outputFile, string line)
            {
                AppendLines(outputFile, new List<string>() { line });
            }

            public static void AppendLines(DataSize dataSize, string module, List<string> lines)
            {
                AppendLines(GetFilePath(DataInputType.Output, dataSize, module), lines);
            }

            public static void AppendLines(string outputFile, List<string> lines)
            {
                File.AppendAllLines(outputFile, lines);
            }

            public static void WriteToFile(string outputFile, string content)
            {
                File.WriteAllText(outputFile, content);
            }

            public static void DeleteFile(string filePath)
            {
                if (File.Exists(filePath)) File.Delete(filePath);
            }

            public static void RenameFile(string filePath)
            {
                if (File.Exists(filePath))
                {
                    var i = 1;
                    var file = new FileInfo(filePath);
                    var dotIndex = filePath.LastIndexOf('.');
                    var part1 = dotIndex < 0 ? filePath : filePath.Substring(0, dotIndex);
                    var extension = dotIndex < filePath.Length - 1 ? filePath.Substring(dotIndex) : "";

                    var newFileFormat = part1 + "_{0}" + extension;
                    var newFile = String.Format(newFileFormat, i);
                    while (File.Exists(newFile))
                    {
                        i++;
                        newFile = String.Format(newFileFormat, i);
                    }
                    File.Move(filePath, newFile);
                }

            }

            public static bool HasExpectedResult(DataSize dataSize, string module)
            {
                return File.Exists(GetFilePath(DataInputType.Expected, dataSize, module));
            }

            public static bool CompareResultToExpected(DataSize dataSize, string module)
            {
                return GetContents(DataInputType.Output, dataSize, module) ==
                       GetContents(DataInputType.Expected, dataSize, module);
            }

            public static long Factorial(int value, int ceiling)
            {
                if (value < 2) return 1;
                return (value * (Factorial(value - 1, ceiling) % ceiling) % ceiling);
            }
        }
    }
}