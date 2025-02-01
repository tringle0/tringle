using System;

//CCC '06 J3 - Cell-Phone Messaging
//https://dmoj.ca/problem/ccc06j3
//2-1-2025

namespace CCC
{
    class CellPhoneMessaging
    {
        public static void Main(String[] args)
        {
            while(true) {
                string input = Console.ReadLine();
                if (input.Equals("halt")) break;
                int time = 0;
                for (int k = 0; k < input.Length; k++){
                    int offset = 0;
                    if (input[k] >= 's') offset = 1;
                    if (input[k] == 's') time++;
                    if (input[k] == 'z'){
                        time++;
                        offset = 2; 
                    }
                    
                    time += (input[k] - 'a' - offset) % 3 + 1 ;
                    if (k > 0 && (input[k]-'a'-offset)/3 == (input[k - 1]-'a'-offset)/3) time+=2;
                }
                Console.WriteLine(time);
            }
        }
    }
}