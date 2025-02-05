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
        static bool IsPrime(int a)
        {
            if (a < 2) return false;
            if (a == 2 || a == 3) return true;
            if (a % 2 == 0 || a % 3 == 0) return false;
            for (int i = 5; i * i <= a; i += 6)
            {
                if (a % i == 0 || a % (i + 2) == 0) return false;
            }
            return true;
        }

        public static void Main(string[] args)
        {
            //sieve
            string[] input = Console.ReadLine().Split(' ');
            int minL = int.Parse(input[0]);
            int startN = int.Parse(input[1]);
            int smallest = int.MaxValue;
            int minSize = (int)Math.Pow(10, minL);
            int current = (int)Math.Max(startN, minSize*minSize/10 + 1);

            for (int k = minSize; k <= current/minSize*10; k *= 10)
            {
                int left = current / k;
                int right = current % k;
                while (!IsPrime(left))
                {
                    right = k/10 + 1;
                    left++;
                }
                if (right < k/10)
                {
                    right = k/10 + 1;
                }
                while (!IsPrime(right))
                {
                    right++;
                }
                
                smallest = Math.Min(left * k + right, smallest);
            }

            Console.WriteLine(smallest);

        }
    }
}
