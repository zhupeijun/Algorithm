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

const int N = 5005;
const int KIND = 26;
const int MOD = 1000000007;

struct node {
    int st, len;
    node(int _st, int _len) { st = _st; len = _len; }
};

typedef vector<node> nset;

char s[N];
int ans[N], C[N][N];
queue<nset> q;

void prepare() {
    C[0][0] = C[1][0] = C[1][1] = 1;
    for(int i = 2; i < N; ++i) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
            if(C[i][j] >= MOD) C[i][j] -= MOD;
        }
    }
}

int main() {
    prepare();
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, qn;
        scanf("%d %d", &n, &qn);
        scanf("%s", s);
        CL(ans, 0);
        while(!q.empty()) q.pop();
        nset rt;
        for(int i = 0; i < n; ++i) rt.pb(node(i, 0));
        q.push(rt);
        while(!q.empty()) {
            nset tn = q.front(); q.pop();
            int sz = tn.size();
            if(tn[0].len > 0) {
                for(int i = 1; i <= sz; ++i) {
                    ans[i] = ans[i] + C[sz][i];
                    if(ans[i] >= MOD) ans[i] -= MOD;
                }
            }
            if(sz == 1) {
                int st = tn[0].st;
                int len = tn[0].len;
                for(int i = st + len; i < n; i++) {
                    ans[1] += 1;
                    if(ans[1] >= MOD) ans[1] -= MOD;
                }
                continue;
            }
            nset *child[KIND] = { NULL };
            for(int i = 0; i < sz; ++i) {
                node k = tn[i];
                int last = k.st + k.len;
                if(last < n) {
                    int c = s[last] - 'a';
                    if(child[c] == NULL) {
                        q.push(nset());
                        child[c] = &q.back();
                    }
                    child[c]->pb(node(k.st, k.len + 1));
                }
            }
        }

        for(int i = 0; i < qn; i++) {
            int ki;
            scanf("%d", &ki);
            if(ki > n) printf("0\n");
            else printf("%d\n", ans[ki]);
        }
    }
    return 0;
}

