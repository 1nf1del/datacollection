﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using Quadruple;

namespace gcj_rotate
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var sr = new StreamReader("A-large-practice.in");
            int T=Convert.ToInt32(sr.ReadLine());
            var sw= new StreamWriter("A-large-practice.out");
            for (int t = 0; t < T; t++)
            {
                var vals=sr.ReadLine().Split(' ');
                int n = Convert.ToInt32(vals[0]);
                int k = Convert.ToInt32(vals[1]);
                string[] str = new string[n];
                for (int i = 0; i < n; i++)
                {
                    str[i]=sr.ReadLine().Replace(".","");
                    int l = str[i].Length;
                    for(int j=0;j<n-l;j++) str[i] = '.'+str[i];
                }
                bool r=false;
                bool b=false;
                for(int i=0;i<n;i++)
                    for (int j = 0; j < n; j++)
                    {
                        if (!r && str[i][j] == 'R')
                        {
                            bool s1 = true;
                            bool s2 = true;
                            bool s3 = true;
                            bool s4 = true;
                            for (int l = 1; l < k; l++)
                            {
                                if (i + k <= n) s1 = s1 && (str[i+l][j] == 'R');
                                if (j + k <= n) s2 = s2 && (str[i][j + l] == 'R');
                                if (i + k <= n && j + k <= n) s3 = s3 && (str[i + l][j + l] == 'R');
                                if (i + k <= n && j - k >= -1) s4 = s4 && (str[i + l][j - l] == 'R');
                            }
                            r=s1 && i + k <= n || s2 && j + k <= n || s3 && i + k <= n && j + k <= n || s4 && i + k <= n && j - k >= -1;
                        }
                        if (!b && str[i][j] == 'B')
                        {
                            bool s1 = true;
                            bool s2 = true;
                            bool s3 = true;
                            bool s4 = true;
                            for (int l = 1; l < k; l++)
                            {
                                if (i + k <= n) s1 = s1 && (str[i+l][j] == 'B');
                                if (j + k <= n) s2 = s2 && (str[i][j + l] == 'B');
                                if (i + k <= n && j + k <= n) s3 = s3 && (str[i + l][j + l] == 'B');
                                if (i + k <= n && j - k >= -1) s4 = s4 && (str[i + l][j - l] == 'B');
                            }
                            b = s1 && i + k <= n || s2 && j + k <= n || s3 && i + k <= n && j + k <= n || s4 && i + k <= n && j - k >= -1;
                        }
                    }
                sw.Write("Case #"+(t+1).ToString()+": ");
                if(r&&b) sw.WriteLine("Both"); else if (r) sw.WriteLine("Red"); else if(b) sw.WriteLine("Blue"); else sw.WriteLine("Neither");

            }
            sw.Close();
            sr.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var sr = new StreamReader("C-large-practice.in");
            int n = Convert.ToInt32(sr.ReadLine());
            var sw = new StreamWriter("C-large-practice.out");
            string per1="1573";
            string per2 = "24530093447546990655";
            string per3 = "1796993094044906218573149716344821084545393295927482030069059550937814268502836551789154546067040725";
            for (int t = 0; t < n; t++)
            {

                int i = Convert.ToInt32(sr.ReadLine());
             /* 
                int a = 2;
                int b = 6;
                int c = a;
                if (i == 0) c = a; else if (i == 1) c = b;else 
                    for (int j = 1; j < i; j++)
                    {

                        c = 6 * b - 4 * a;
                        while (c < 0) c += 1000;
                        c = c % 1000;
                        a = b;
                        b = c;

                    }
                sw.WriteLine("Case #" + (t + 1).ToString() + ": " + (c-1).ToString("000"));*/
                string let1 = "";
                string let2 = "";
                string let3 = "";
                if (i < 2) let3 = "0"; else let3 = per3[(i - 3) % per3.Length].ToString();
                if (i < 1) let2 = "0"; else let2 = per2[(i - 2) % per2.Length].ToString();
                let1 = per1[i % per1.Length].ToString();
                sw.WriteLine("Case #" + (t + 1).ToString() + ": " + let3+let2+let1);
               
            }
            sw.Close();
            sr.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            var sr = new StreamReader("B-small-practice (1).in");
            int c = Convert.ToInt32(sr.ReadLine());
            var sw = new StreamWriter("B-small-practice (1).out");
            List<Point> E0=new List<Point>();
            List<Point> E1=new List<Point>();

            for (int t = 0; t < c; t++)
            {
                int n = Convert.ToInt32(sr.ReadLine());
                int m = Convert.ToInt32(sr.ReadLine());
                for (int i = 0; i < m; i++)
                {
                    var vals = sr.ReadLine().Split(' ');
                    int T = Convert.ToInt32(vals[0]);
                    for (int j = 0; j < T; j++)
                        if (vals[1 + j*2 + 1] == "0") E0.Add(new Point(i, Convert.ToInt32(vals[1 + j*2]))); else E1.Add(new Point(i, Convert.ToInt32(vals[1 + j*2])));
                    // есть граф

                }
                sw.WriteLine("Case #" + (t + 1).ToString() + ": ");       
            }
            sw.Close();
            sr.Close();
  
        }

        private void button4_Click(object sender, EventArgs e)
        {
            var sr = new StreamReader("A-small-attempt0.in ");
            var sw = new StreamWriter("A-small-attempt0.out");
            int T = Convert.ToInt32(sr.ReadLine());
            for (int t = 0; t < T; t++)
            {
                int r1 = Convert.ToInt32(sr.ReadLine());
                int i = 1;
                for (; i < r1; i++) sr.ReadLine();
                var row1 = sr.ReadLine().Split(' ');
                for (; i < 4; i++) sr.ReadLine();
                int r2 = Convert.ToInt32(sr.ReadLine());
                i = 1;
                for (; i < r2; i++) sr.ReadLine();
                var row2 = sr.ReadLine().Split(' ');
                for (; i < 4; i++) sr.ReadLine();
                var res = row1.Intersect(row2).ToList();
                sw.Write("Case #" + (t + 1).ToString() + ": ");
                if (res.Count >1) sw.WriteLine("Bad magician!");
                else
                    if (res.Count == 1) sw.WriteLine(res[0]); else
                        sw.WriteLine("Volunteer cheated!");

            }
            sr.Close();
            sw.Close();
        }
    }
}