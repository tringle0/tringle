using System;
using System.Collections.Generic;
public class CrossingField
{
    public struct Tile
    {
        public int x, y, lastheight;
        public void set(int x, int y, int l) { this.x = x; this.y = y; this.lastheight = l; }

    }

    public static void Main(string[] args)
    {
        string input = Console.ReadLine();
        string[] inputs = new string[2];
        inputs = input.Split(' ');

        int h = Convert.ToInt16(inputs[1]);
        int n = Convert.ToInt16(inputs[0]);

        int[,] grid = new int[n,n];

        for (int k = 0; k < n; k++)
        {
            input = Console.ReadLine();
            string[] currentLine = input.Split(' ');
            for (int i = 0; i < currentLine.Length; i++)
            {
                grid[k,i] = Convert.ToInt16(currentLine[i]);
            }
        }


        Queue<Tile> bfs = new Queue<Tile>();

        Tile init = new Tile();
        int lastheight = grid[0, 0];
        init.set(0,0,lastheight);
        bfs.Enqueue(init);
        Tile current, nextTile = new Tile();
        
        while (true)
        {
            if (bfs.Count == 0)
            {
                Console.WriteLine("no");
                break;
            }

            
            current = bfs.Dequeue();

            if (current.x >= 0 && current.x < n && current.y >= 0 && current.y < n)
            {
                if (grid[current.x,current.y] != -1)
                {
                    if (Math.Abs(current.lastheight - grid[current.x,current.y]) <= h)
                    {
                        lastheight = grid[current.x, current.y];
                        nextTile.set(current.x + 1, current.y, lastheight);
                        bfs.Enqueue(nextTile);
                        nextTile.set(current.x, current.y + 1, lastheight);
                        bfs.Enqueue(nextTile);
                        nextTile.set(current.x - 1, current.y, lastheight);
                        bfs.Enqueue(nextTile);
                        nextTile.set(current.x, current.y - 1, lastheight);

                        bfs.Enqueue(nextTile);
                        
                        grid[current.x,current.y] = -1;

                        

                        if (current.x == n - 1 && current.y == n - 1)
                        {
                            Console.WriteLine("yes");
                            break;
                        }
                    }
                }
            }
        }
    }
}
