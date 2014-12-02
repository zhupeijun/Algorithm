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

typedef long long LL;

using namespace std;

const int N = 100005;
const int M = 2000005;
const int K = 150000;

int a[N], ans[N], fn, pos[M], dep[N];
vector<int> tree[N], fac;
stack<int> fp[K];
bool is_prime[M];

void get_factor() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < M; i++)
        if(is_prime[i]) {
            for(int j = 2; 1LL * j * i < M; j++)
                is_prime[i * j] = false;
            pos[i] = fac.size();
            fac.push_back(i);
        }
    fn = fac.size();
}

void dfs(int u, int pre) {
    vector<int> tmp;
    int x = a[u];
    for(int i = 0; i < fn; i++) {
        if(1LL * fac[i] * fac[i] > a[u]) break;
        if(x % fac[i] == 0) {
            while(x % fac[i] == 0)
                x /= fac[i];
            tmp.push_back(fac[i]);
        }
    }
    if(x > 1) tmp.push_back(x);

    int m = tmp.size(), res = -1;
    for(int i = 0; i < m; i++) {
        int p = pos[tmp[i]];
        if(fp[p].size() > 0) {
            int top = fp[p].top();
            if(res == -1 || dep[res] < dep[top]) {
                res = top;
            }
        }
        fp[p].push(u);
    }
    ans[u] = res;

    int tz = tree[u].size();
    for(int k = 0; k < tz; k++) {
        int v = tree[u][k];
        if(v != pre) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    }

    for(int i = 0; i < m; i++)
        fp[pos[tmp[i]]].pop();
}

int main() {
    int n, q;
    get_factor();
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dep[1] = 0;
    dfs(1, -1);
    for(int i = 0; i < q; i++) {
        int t, v, w;
        scanf("%d", &t);
        if(t == 1) {
            scanf("%d", &v);
            printf("%d\n", ans[v]);
        } else {
            scanf("%d %d", &v, &w);
            a[v] = w;
            dfs(1, -1);
        }
    }
    return 0;
}

