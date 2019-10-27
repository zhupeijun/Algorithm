#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int main() {
    int n;
    scanf("%d", &n);
    map<int, int> index;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int k = i * 1005 + j;
            index[k] = m++;
        }
    }

    vector<vector<int>> adj(m);
    vector<int> d(m, 0);
    for (int i = 0; i < n; ++i) {
        int prev = -1;
        for (int j = 1; j < n; ++j) {
            int v;
            int u = i;
            scanf("%d", &v);
            --v;
            if (u > v) {
                swap(u, v);
            }
            int k = index[u * 1005 + v];
            if (prev != -1) {
                adj[prev].push_back(k);
                ++d[k];
            }
            prev = k;
        }
    }

    vector<int> remove;
    for (int i = 0; i < m; ++i) {
        if (d[i] == 0) {
            remove.push_back(i);
        }
    }

    int total = 0;
    int done = 0;
    while  (!remove.empty()) {
        vector<int> tmp;
        int rn = remove.size();
        for (int i = 0; i < rn; ++i) {
            int u = remove[i];
            for (int j = 0; j < adj[u].size(); ++j) {
                int v = adj[u][j];
                --d[v];
                if (d[v] == 0) {
                    tmp.push_back(v);
                }
            }
            ++done;
        }
        ++total;
        remove = tmp;
    }
    if (done == m) {
        printf("%d\n", total);
    } else {
        printf("-1\n");
    }
    return 0;
}

