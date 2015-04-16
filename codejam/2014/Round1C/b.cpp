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

const int M = 30;
const int MOD = 1000000007;

char cars[105][105];
int bg[M], mid[M], ed[M], same[M], adj[M];

bool all_same(char s[], int n) {
    for(int i = 1; i < n; i++)
        if(s[i] != s[i - 1]) return false;
    return true;
}

ll tgamma(ll a, ll mod) {
    ll res = 1;
    for(ll i = 1; i <= a; i++) res = (res * i) % mod;
    return res;
}

int main() {
    int cn;
    scanf("%d", &cn);
    for(int ci = 1; ci <=cn; ci++) {
        int n;
        scanf("%d", &n);
        bool bad = false;
        for(int i = 0; i < 26; i++) bg[i] = mid[i] = ed[i] = same[i] = 0;
        for(int i = 0; i < n; i++) {
            scanf("%s", cars[i]);
            int n = strlen(cars[i]);
            if(cars[i][0] == cars[i][n - 1]) {
                if(all_same(cars[i], n)) {
                    same[cars[i][0] - 'a'] ++;
                } else {
                    bad = true;
                }
            } else {
                int bi = cars[i][0] - 'a', ei = cars[i][n - 1] - 'a';
                bg[bi]++; ed[ei]++;
                if(bg[bi] > 1 || ed[ei] > 1) bad = true;
                int head = 1, tail = n - 2;
                while(head < n && cars[i][head] == cars[i][head - 1]) head++;
                while(tail >= head && cars[i][tail] == cars[i][tail + 1]) tail--;
                for(int j = head; j <= tail; j++) {
                    int x = cars[i][j] - 'a';
                    mid[x] ++;
                    if(mid[x] > 1) bad = true;
                    while(j + 1 <= tail && cars[i][j] == cars[i][j + 1]) j++;
                }
            }
        }
        for(int i = 0; i < 26; i++)
            if(mid[i] > 0 && (bg[i] > 0 || ed[i] > 0 || same[i] > 0))
                bad = true;
        printf("Case #%d: ", ci);
        if(bad) { printf("0\n"); continue; }
        int tot = 0;
        CL(adj, 0);
        bool has = false;
        for(int i = 0; i < 26; i++) {
            if(bg[i] || ed[i]) {
                adj[i] = 1;
                has = true;
            }
            if(bg[i] && !ed[i]) tot++;
        }
        if(has && tot == 0) { printf("0\n"); continue; }
        ll ans = 1;
        for(int i = 0; i < 26; i++) {
            if(same[i] > 0) {
                if(!adj[i]) tot++;
                ans *= tgamma(same[i], MOD);
                ans %= MOD;
            }
        }
        ans *= tgamma(tot, MOD);
        ans %= MOD;
        printf("%d\n",(int)ans);
    }
    return 0;
}

