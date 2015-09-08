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
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n;
    scanf("%d", &n);
    vector<pii> a;
    vector<bool> rd;
    for(int i = 0; i <n; ++i) {
        int x;
        scanf("%d", &x);
        a.pb(mp(x, i)); rd.pb(false);
    }
    sort(a.begin(), a.end());
    int ans = 1;
    if (n >= 2) {
        int cur = 0;
        vector<int> r;
        r.pb(0); r.pb(n - 1);
        fill(rd.begin(), rd.end(), false);
        rd[0] = rd[n - 1] = true;
        while(cur < n && a[cur].first <= ans) {
            int idx = a[cur].second;
            if(!rd[idx]) { r.pb(idx); rd[idx] = true; }
            cur++;
        }
        while(true) {
            vector<int> tmp;
            for(int idx : r) {
                if(idx - 1 >= 0 && !rd[idx - 1]) {
                    tmp.pb(idx - 1);
                    rd[idx - 1] = true;
                }
                if(idx + 1 < n && !rd[idx + 1]) {
                    tmp.pb(idx + 1);
                    rd[idx + 1] = true;
                }
            }
            while(cur < n && a[cur].first <= ans + 1) {
                int idx = a[cur].second;
                if(!rd[idx]) { tmp.pb(idx); rd[idx] = true; }
                cur++;
            }
            r = tmp;
            if(r.size() == 0) break;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}

