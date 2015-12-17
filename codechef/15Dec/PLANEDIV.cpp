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

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> lines;
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0) { d = b; b = 1; }
        else if(b == 0) { d = a; a = 1; }
        else {
            int g = gcd(abs(a), abs(b));
            if (a < 0) g = -g;
            a /= g; b /= g; d = g;
        }
        if (c == 0) d = 0;
        else {
            int g = gcd(abs(d), abs(c));
            if (c < 0) g = -g;
            c /= g; d /= g;
        }
        lines.push_back({a, b, c, d});
    }
    sort(lines.begin(), lines.end());
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) cnt++;
        else {
            if (lines[i - 1][0] == lines[i][0] && lines[i - 1][1] == lines[i][1]) {
                if (lines[i - 1][2] != lines[i][2] || lines[i - 1][3] != lines[i][3]) {
                    cnt++;
                }
            } else {
                cnt = 1;
            }
        }
        if (cnt > ans) ans = cnt;
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

