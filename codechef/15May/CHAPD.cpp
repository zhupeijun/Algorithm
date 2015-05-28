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

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        ll a, b;
        bool ans = false;
        scanf("%lld %lld", &a, &b);
        if(b == 1) ans = true;
        else if(a == 1) ans = false;
        else {
            while(true) {
                ll g = gcd(a, b);
                if (g == 1) { ans = false; break; }
                else if(g == b) { ans = true; break; }
                else {
                    b /= g;
                }
            }
        }
        if(ans) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

