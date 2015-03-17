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

const int N = 100005;

char s[N];
char fd1[N], fd2[N];

char next(char c) {
    return c == 'B' ? 'G' : 'B';
}

ll count0(char st, int n) {
    char cur = st;
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != cur) cnt++;
        cur = next(cur);
    }
    return cnt;
}

ll count1(char st, int n) {
    queue<int> q;
    char cur = st;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] != cur) {
            if(q.size() == 0 || s[i] == s[q.front()]) {
                q.push(i);
            } else {
                int idx = q.front();
                ans += i - idx;
                q.pop();
            }
        }
        cur = next(cur);
    }
    return ans;
}

int solve(int bn, int gn, int n, int type) {
    if (bn != gn) {
        char st = bn > gn ? 'B' : 'G';
        if (type == 0) {
            int cnt = count0(st, n);
            return cnt / 2;
        } else {
            return count1(st, n);
        }
    } else {
        if(type == 0) {
            int cnt = min(count0('B', n), count0('G', n));
            return cnt / 2;
        } else {
            return min(count1('B', n), count1('G', n));
        }
    }
}


int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int type;
        scanf("%d", &type);
        scanf("%s", s);

        int gn = 0, bn = 0;
        int n = strlen(s);
        for(int i = 0; i < n; i++) {
            if(s[i] == 'B') bn++;
            if(s[i] == 'G') gn++;
        }

        if (abs(bn - gn) > 1) printf("-1\n");
        else {
            printf("%d\n", solve(bn, gn, n, type));
        }
    }
    return 0;
}

