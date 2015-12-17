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
#include <numeric>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    int m = 1 << n, cnt = 0;
    for (int i = 0; i < m; ++i) {
        int x = i, j = 1;
        vector<int> st;
        while (x) {
            if (x & 1 ) st.pb(j);
            x >>= 1; ++j;
        }
        if (st.size() == k) {
            if (accumulate(st.begin(), st.begin() + k - 1, 0) > st[k - 1]) {
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

