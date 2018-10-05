using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp
{
    class Peek
    {
        static int PeekFinder1D(int[] Array, int low, int high)
        {
            int mid = (low + high) / 2;

            if (mid >= 0 && Array[mid] < Array[mid - 1])
                return PeekFinder1D(Array, 0, mid - 1);
            else if (mid < high && Array[mid] < Array[mid + 1])
                return PeekFinder1D(Array, mid + 1, high);
            else
                return mid;
        }

        // static Tuple PeekFinder2D(int[][] Array, int uRow, int dRow)
        //{

        //}

        static void Main()
        {
            
            int[] Array = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

            int t = PeekFinder1D(Array, 0, 9);
            Console.WriteLine("The Peek exists at: " + PeekFinder1D(Array, 0, 9));
            Console.ReadKey();
        }

    }
}
