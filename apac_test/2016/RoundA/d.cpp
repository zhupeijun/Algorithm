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
#include <list>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

int M[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void solve() {
    int S, R, C;
    scanf("%d %d %d", &S, &R, &C);
    vector<pii> ctrl;
    for (int i = 0; i < S; ++i) {
        char tr[2] = { 0 };
        int tm;
        scanf("%d %s", &tm, tr);
        ctrl.push_back(mp(tm, tr[0] == 'R' ? 1 : -1));
    }
    set<pii> busy;
    list<pii> body;
    set<pii> eaten;
    int d = 3;
    pii start = mp(0, 0);
    body.push_back(start);
    busy.insert(start);
    for (int i = 0, j = 0; i < 1200005; ++i) {
        if (ctrl.size() > j && i == ctrl[j].first) {
            d = (d + ctrl[j].second + 4) % 4;
            ++j;
        }
        pii nxt = mp((body.back().first + M[d][0] + C) % C, (body.back().second + M[d][1] + R) % R);
        if ((((nxt.first + nxt.second) & 1) == 0) || (eaten.find(nxt) != eaten.end())) {
            busy.erase(body.front());
            body.pop_front();
        } else {
            eaten.insert(nxt);
        }
        if (busy.find(nxt) != busy.end()) {
            printf("%d", static_cast<int>(body.size()) + 1);
            return;
        }
        busy.insert(nxt);
        body.push_back(nxt);
    }
    printf("%d", static_cast<int>(body.size()));
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        solve();
        printf("\n");
    }
    return 0;
}

