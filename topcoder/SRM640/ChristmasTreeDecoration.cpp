#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

bool good[55][55], vis[55];

class ChristmasTreeDecoration {
public:
    int solve(vector <int> col, vector <int> x, vector <int> y) {
        memset(good, false, sizeof(good));
        int m = x.size();
        int n = col.size();
        for(int i = 0; i < m; i++) good[x[i]][y[i]] = good[y[i]][x[i]] = true;
        int sn = 0;
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; i++) {
            if(vis[i]) continue;
            sn ++;
            queue<int> q;
            q.push(i); vis[i] = true;
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int j = 1; j <= n; j++) {
                    if(!vis[j] && good[u][j] && col[u - 1] != col[j - 1]) {
                        q.push(j); vis[j] = true;
                    }
                }
            }
        }
        return sn - 1;
    }
};