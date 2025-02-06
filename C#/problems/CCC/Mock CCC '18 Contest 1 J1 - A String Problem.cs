using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Mock CCC '18 Contest 1 J1 - A String Problem
//https://dmoj.ca/problem/nccc1j1
//2-4-2025

namespace CCC
{
    class StringProblem
    {
        public static void Main(string[] args)
        {
            string input = Console.ReadLine();
            int a = Convert.ToInt32(input);
            int i;
            for (i = a+1; Convert.ToString(i).Contains("0"); i++) ;
            Console.WriteLine(i);
        }
    }
}