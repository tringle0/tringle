using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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