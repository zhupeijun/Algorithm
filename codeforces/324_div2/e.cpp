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

const int N = 2005;
int idx1[N], idx2[N], p1[N], p2[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p1[i]);
        idx1[p1[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p2[i]);
        idx2[p2[i]] = i;
    }
    vector<pair<int, int>> ans;
    int cost = 0;
    for (int i = 0; i < n; ++i) {
        if (p1[i] == p2[i]) continue;
        int k = idx1[p2[i]]; cost += k - i;
        for (int j = k - 1; j >= 0; --j) {
            if (idx2[p1[j]] >= k) {
                ans.push_back(make_pair(j + 1, k + 1));
                swap(idx1[p1[j]], idx1[p1[k]]);
                swap(p1[j], p1[k]);
                k = j;
            }
        }
    }
    printf("%d\n", cost);
    printf("%d\n",(int)ans.size());
    for(auto sp : ans) printf("%d %d\n", sp.first, sp.second);
    return 0;
}

