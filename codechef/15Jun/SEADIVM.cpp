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

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 105;
const int M = 1005;
int a[N][N], tot[M], cnt[M];
bool vis[N][M];

vi make_rec(int x1, int y1, int x2, int y2) {
    vi rec;
    rec.pb(x1); rec.pb(y1); rec.pb(x2), rec.pb(y2);
    return rec;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        CL(tot, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
                ++tot[a[i][j]];
            }
        }
        CL(cnt, 0);
        vector<vi> ans;
        for(int i = 0; i < n; ++i) {
            int bj = -1, ej = -1;
            for(int j = 0; j < m; ++j) {
                if((cnt[a[i][j]] << 1) < tot[a[i][j]]) {
                    ++cnt[a[i][j]];
                    if(bj == -1) bj = ej = j;
                    else ej = j;
                } else {
                    if(bj != -1) {
                        vi r = make_rec(i, bj, i, ej);
                        ans.pb(r);
                        bj = ej = -1;
                    }
                }
            }
            if(bj != -1) {
                vi r = make_rec(i, bj, i, ej);
                ans.pb(r);
            }
        }

        vector<vi> res;
        int tn = ans.size();
        map<pii, pii> M;
        for(int i = 0; i < tn; ++i) {
            pii c = make_pair(ans[i][1], ans[i][3]);
            if(M.find(c) == M.end()) {
                M[c] = make_pair(ans[i][0], ans[i][0]);
            } else {
                if(ans[i][0] - M[c].second == 1) {
                    M[c].second = ans[i][0];
                } else {
                    res.pb(make_rec(M[c].first, c.first, M[c].second, c.second));
                    M[c] = make_pair(ans[i][0], ans[i][0]);
                }
            }
        }
        map<pii, pii>::iterator it;
        for(it = M.begin(); it != M.end(); ++it) {
            res.pb(make_rec(it->second.first, it->first.first, it->second.second, it->first.second));
        }
        int rn = res.size();
        printf("%d\n", rn);
        for(int i = 0; i < rn; ++i) {
            for(int k = 0; k < 4; ++k) {
                printf("%d", res[i][k] + 1);
                if(k == 3) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}

