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

typedef long long ll;
typedef pair<int, int> pii;

bool cmp(const pii& a, const pii& b) {
    return a.second < b.second;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<pii> kds;
        for(int i = 0; i < n; i++) {
            pii kd;
            scanf("%d %d", &kd.first, &kd.second);
            kds.push_back(kd);
        }
        sort(kds.begin(), kds.end(), cmp);
        int last = -1, ans = 0;
        for(int i = 0; i < n; i++) {
            pii kd = kds[i];
            if(kd.first <= last) continue;
            last = kd.second;
            ans ++;
        }
        printf("%d\n", ans);
    }
    return 0;
}

