using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace CodeChef {
public class Chsign {

    public static void Main ()
    {
        int T = int.Parse(Console.ReadLine ());
        for (int i = 0; i < T; ++i) {
            Solve ();
        }
    }

    public static void Solve ()
    {
        int n = int.Parse (Console.ReadLine ());
        var a = Console.ReadLine ().Split ().Select (x => int.Parse(x)).ToList();

        var dp = new List<List<long>>{
            new List<long> {0, 0, 0},
            new List<long> {0, 0, 0}
        };

        var log = new List<List<Log>> ();

        int k = 0, prev = -1;
        for (int i = 0; i < n; ++i) {
            if ((i - 1 < 0 || a[i - 1] > a[i]) && (i + 1 >= n || a[i + 1] > a[i])) {
                bool conflict = prev >= 0 && prev + 2 == i && a[i] + a[prev] - a[i - 1] >= 0;
                int nxt = (k + 1) & 1;

                var t = new List<Log> ();
                if (conflict) {

                    int idx = dp[k][1] > dp[k][2] ? 1 : 2;
                    dp[nxt][0] = dp[k][idx] + a[i];
                    dp[nxt][1] = dp[k][0];
                    dp[nxt][2] = dp[k][1];

                    t.Add (new Log (true , i, idx));
                    t.Add (new Log (false, i, 0));
                    t.Add (new Log (false, i, 1));
                } else {

                    int idx = dp[k].IndexOf (dp[k].Max ());
                    dp[nxt][0] = dp[k][idx] + a[i];
                    dp[nxt][1] = dp[k][0];
                    dp[nxt][2] = dp[k][1];

                    t.Add (new Log (true , i, idx));
                    t.Add (new Log (false, i, 0));
                    t.Add (new Log (false, i, 1));
                }

                log.Add (t);

                k = nxt;
                prev = i;
            }
        }

        int last = k & 1;

        int cur = dp[last].IndexOf(dp[last].Max());
        int m = log.Count;
        for (int i = m - 1; i >= 0; --i) {
            var x = log[i][cur];
            if (x.selected) {
                a[x.index] *= -1;
            }

            cur = x.previous;
        }

        Console.WriteLine (String.Join(" ", a.Select(x => x.ToString()).ToList()));
    }

    public class Log {
        public bool selected;
        public int  index;
        public int  previous;

        public Log (bool sel, int idx, int prev)
        {
            selected = sel;
            index    = idx;
            previous = prev;
        }
    }
}
}
