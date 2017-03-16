﻿using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Data;

class GCJ
{
    protected StreamReader sr;
    protected StreamWriter sw;
    protected char[] splitors = { ' ', '\t' };

    public virtual void Input(int testcase)
    {
    }

    public virtual void Search(int testcase)
    {
    }

    public void Run(string fileInput, string fileOutput)
    {
        sr = new StreamReader(fileInput);
        sw = new StreamWriter(fileOutput);
        int testcase = Int32.Parse(sr.ReadLine());
        for (int i = 1; i <= testcase; i++)
        {
            Console.Write("Case #" + i + ":");
            sw.Write("Case #" + i + ":");
            Input(i);
            Search(i);
            Console.WriteLine(" finished");
        }
        sw.Flush();
    }
}

class PB : GCJ
{
    public PB(string fileInput, string fileOutput)
    {
        base.Run(fileInput, fileOutput);
    }

    int n, m;
    int[][] a, w;

    public override void Input(int testcase)
    {
        base.Input(testcase);
        string[] str = sr.ReadLine().Split(splitors, StringSplitOptions.RemoveEmptyEntries);
        n = Int32.Parse(str[0]);
        m = Int32.Parse(str[1]);
        a = new int[n][];
        w = new int[n][];
        for (int i = 0; i < n; i++)
        {
            a[i] = new int[m];
            w[i] = new int[m];
        }
        for (int i = 0; i < n; i++)
        {
            str = sr.ReadLine().Split(splitors, StringSplitOptions.RemoveEmptyEntries);
            for (int j = 0; j < m; j++)
            {
                a[i][j] = Int32.Parse(str[j]);
                w[i][j] = 100;
            }
        }
    }

    public override void Search(int testcase)
    {
        base.Search(testcase);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] > 100)
                {
                    sw.WriteLine(" NO");
                    return;
                }

        for (int loop = 0; loop <= n * m; loop++)
        {
            /*
            if (testcase == 57)
            {
                for (int x = 0; x < n; x++)
                {
                    for (int y = 0; y < m; y++)
                        Console.Write(w[x][y] + " ");
                    Console.WriteLine();
                }
                for (int x = 0; x < n; x++)
                {
                    for (int y = 0; y < m; y++)
                        Console.Write(a[x][y] + " ");
                    Console.WriteLine();
                }
                Console.WriteLine();
            }
            */ 

            int minx = -1, miny = -1, i, j;
            for (i = 0; i < n; i++)
                for (j = 0; j < m; j++)
                {
                    if (w[i][j] > a[i][j])
                        if (minx == -1 || (a[i][j] < a[minx][miny]))
                        {
                            minx = i;
                            miny = j;
                        }
                }
            if (minx == -1)
            {
                sw.WriteLine(" YES");
                return;
            }

            for (i = 0; i < n; i++)
                if (a[i][miny] > a[minx][miny])
                    break;
            if (i == n)
            {
                for (int x = 0; x < n; x++)
                    if (w[x][miny] > a[minx][miny])
                        w[x][miny] = a[minx][miny];
                continue;
            }
            for (j = 0; j < m; j++)
                if (a[minx][j] > a[minx][miny])
                    break;
            if (j == m)
            {
                for (int y = 0; y < m; y++)
                    if (w[minx][y] > a[minx][miny])
                        w[minx][y] = a[minx][miny];
                continue;
            }
            else
            {
                sw.WriteLine(" NO");
                return;
            }
        }
    }
}
