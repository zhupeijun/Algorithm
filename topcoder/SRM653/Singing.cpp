#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

#define CL(a,b) memset(a, b, sizeof(a))
#define pb push_back

const int M = 1005;

int c[M][M], vis[M];
vector<int> adj[M];

class Singing {
public:
    bool dfs(int u, int t) {
        if(u == t) return true;
        vis[u] = true;
        int m = adj[u].size();
        for(int i = 0; i < m; i++) {
            int v = adj[u][i];
            if(!vis[v] && c[u][v] && dfs(v, t)) {
                return c[u][v]--, c[v][u]++, true;
            }
        }
        return false;
    }
    int solve(int N, int low, int high, vector <int> pitch) {
        CL(c, 0);
        int pn = pitch.size();
        for(int i = 1; i < low; i++) { c[0][i] = pn; adj[0].pb(i); }
        for(int i = high + 1; i < N + 1; i++) { c[i][N + 1] = pn; adj[i].pb(N + 1); }
        for(int i = 1; i < pn; i++) {
            int x = pitch[i - 1], y = pitch[i];
            if(c[x][y] == 0) { adj[x].pb(y); adj[y].pb(x); }
            c[x][y]++; c[y][x]++;
        }
        int ans = 0;
        while(true) {
            CL(vis, 0);
            if(dfs(0, N + 1)) ans++;
            else break;
        }
        return ans;
    }
};