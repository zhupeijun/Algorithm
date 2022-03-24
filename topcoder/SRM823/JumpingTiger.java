import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class JumpingTiger {
    private static final int[][] DIR = {{0,-1},{-1,0},{0,1},{1,0}};

    public int travel(String[] plan) {
        int n = plan.length, m = plan[0].length();

        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> a[2]));

        int tx = -1, ty = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (plan[i].charAt(j) == 'T') {
                    tx = i; ty = j;
                }
            }
        }

        boolean[][][] vis = new boolean[n][m][5];

        q.add(new int[] { tx, ty, 0, -1, 0 });

        while (!q.isEmpty()) {
            int[] t = q.poll();
            //System.out.println(Arrays.toString(t));

            if (vis[t[0]][t[1]][(t[3]+5)%5]) continue;
            vis[t[0]][t[1]][(t[3]+5)%5] = true;

            if (plan[t[0]].charAt(t[1]) == 'L' && t[3] == -1) return t[2];


            if (t[3] == -1) {
                for (int j = 0; j < m; ++j) {
                    int dis = Math.abs(t[1]-j);
                    if (plan[t[0]].charAt(j) != '#') {
                        if (dis == 1) {
                            q.add(new int[] { t[0], j, t[2]+1, -1, 0});
                        } else {
                            q.add(new int[] { t[0], j, t[2]+1, j<t[1]?0:2, dis });
                        }
                    }
                }

                for (int i = 0; i < n; ++i) {
                    int dis = Math.abs(t[0]-i);
                    if (plan[i].charAt(t[1]) != '#') {
                        if (dis == 1) {
                            q.add(new int[] { i, t[1], t[2]+1, -1, 0});
                        } else {
                            q.add(new int[] { i, t[1], t[2]+1, i<t[0]?1:3, dis});
                        }
                    }
                }
            } else {
                int x = t[0], y = t[1], dis = t[4];
                for (int i = 0; i < dis-1; ++i) {
                    x += DIR[t[3]][0];
                    y += DIR[t[3]][1];
                    if (x >= 0 && x < n && y >= 0 && y < m && plan[x].charAt(y) != '#') {
                        q.add(new int[]{x, y, t[2] + 1, i>0?t[3]:-1, i+1});
                    }
                }
            }
        }
        return -1;
    }
}

