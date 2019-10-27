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

char s[100005];
char t[100005];

int p[100005][26];

int main() {
    scanf("%s", s);
    scanf("%s", t);

    int sn = strlen(s);
    int a[26];
    memset(a, -1, sizeof(a));
    for (int i = sn - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            p[i][j] = a[j];
        }

        a[s[i] - 'a'] = i;
    }

    for (int i = sn - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            p[i][j] = a[j];
        }
        a[s[i] - 'a'] = i;
    }

    int tn = strlen(t);
    ll res = 0;
    int next = -1;
    for (int i = 0; i < tn; ++i) {
        int cur = next;
        if (i == 0) {
            next = a[t[i] - 'a'];
        } else {
            next = p[cur][t[i] - 'a'];
        }

        if (next == -1) {
            res = -1;
            break;
        } else {
            if (next <= cur) {
                res += sn - cur + next;
            } else {
                res += next - cur;
            }
            cur = next;
        }
    }
    printf("%lld\n", res);
    return 0;
}

