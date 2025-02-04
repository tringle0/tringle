using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CCC
{
    class PrimeProblem
    {
        public static void Main(string[] args)
        {
            //sieve
            string[] input = Console.ReadLine().Split(' ');
            int minL = Convert.ToInt32(input[0]);
            int startN = Convert.ToInt32(input[1]);

            bool[] sieve = new bool[startN+1];
            for(int k = 2; k < startN+1; k++)
            {
                sieve[k] = true;
            }
            for (int k = 2; k < startN+1; k++)
            {
                for (int i = k*2; i < sieve.Length; i += k)
                {
                    sieve[i] = false;
                }
            }

            string current = Convert.ToString(startN);
            bool found = false;

            while (true)
            {
                for (int k = minL; k <= current.Length - minL; k++)
                {
                    string left = current.Substring(0, k);
                    string right = current.Substring(k, current.Length - k);
                    if (Convert.ToInt32(left) > sieve.Length || Convert.ToInt32(right) > sieve.Length) break;
                    if (sieve[Convert.ToInt32(left)] && sieve[Convert.ToInt32(right)])
                    {
                        found = true;
                        break;
                    }
                    
                }
                if (found)
                {
                    break;
                }
                
                current = Convert.ToString(Convert.ToInt32(current) + 1);
            }

            Console.WriteLine(current);

        }
    }
}
