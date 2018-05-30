using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;

public class Fakebs {
    public static void Main ()
    {
        int T = int.Parse(Console.ReadLine());
        for (int i = 0; i < T; ++i) {
            Solve ();
        }
    }

    public static void Solve ()
    {
        var input = Console.ReadLine ().Split().Select (x => int.Parse(x));
        int N = input.First();
        int Q = input.Last ();

        var a  = Console.ReadLine ().Split().Select(x => int.Parse(x)).ToList();
        var p  = a.Select ((x, i) => new { idx = i, val = x }).ToDictionary(x => x.val, x => x.idx);
        var sp = a.OrderBy (x => x).Select ((x, i) => new { idx = i, val = x }).ToDictionary (x => x.val, x => x.idx);

        for (int i = 0; i < Q; ++i) {
            int x = int.Parse(Console.ReadLine());
            int k = p[x];

            int small = sp[x], large = N - 1 - small;

            int l = 0, r = N - 1, mid;

            int needL = 0, needS = 0, stayL = 0, stayS = 0;
            while (l <= r) {
                mid = (l + r) / 2;

                if (k > mid) {
                    l = mid + 1;
                    if (x < a[mid]) {
                        ++needS;
                    } else {
                        ++stayS;
                    }
                } else if (k < mid) {
                    r = mid - 1;
                    if (x > a[mid]) {
                        ++needL;
                    } else {
                        ++stayL;
                    }
                } else {
                    break;
                }
            }

            if (needL + stayL > large || needS + stayS > small) {
                Console.WriteLine(-1);
                continue;
            }

            Console.WriteLine (Math.Max(needL, needS));
        }
    }
}
