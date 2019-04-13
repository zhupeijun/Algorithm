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
    int x, y, z, k;
    scanf("%d %d %d %d", &x, &y, &z, &k);
    vector<ll> a(x), b(y), c(z);
    for (int i = 0; i < x; ++i) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < y; ++i) {
        scanf("%lld", &b[i]);
    }
    for (int i = 0; i < z; ++i) {
        scanf("%lld", &c[i]);
    }

    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            q.push(a[i] + b[j]);
            if (q.size() > 3000) {
                q.pop();
            }
        }
    }

    vector<ll> d;
    while (!q.empty()) {
        d.push_back(q.top());
        q.pop();
    }

    int t = d.size();
    for (int i = 0; i < z; ++i) {
        for (int j = 0; j < t; ++j) {
            q.push(c[i] + d[j]);
            if (q.size() > 3000) {
                q.pop();
            }
        }
    }

    vector<ll> e;
    while (!q.empty()) {
        e.push_back(q.top());
        q.pop();
    }

    int ez = e.size();
    for (int i = 0; i < k; ++i) {
        printf("%lld\n", e[ez - 1 - i]);
    }
    return 0;
}

