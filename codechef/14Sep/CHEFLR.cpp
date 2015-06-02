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

typedef long long LL;

using namespace std;

char s[100005];

const int MOD = 1000000007;

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        scanf("%s", s);
        int n = strlen(s), ans = 1;
        for(int i = 0; i < n; i++) {
            if(i & 1) {
                if(s[i] == 'l') ans = ans * 2 - 1;
                else ans = ans * 2 + 1;
            } else {
                if(s[i] == 'l') ans = ans * 2;
                else ans = ans * 2 + 2;
            }
            ans = ans % MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}

