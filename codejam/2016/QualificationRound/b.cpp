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
#define pc __builtin_popcount

typedef long long ll;
typedef pair<int, int> pii;

char s[105];

int solve() {
    scanf("%s", s);
    int n = strlen(s), ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i - 1] != s[i]) ++ans;
    }
    return ans -= (s[n - 1] == '+');
}

int main() {
    int case_n;
    scanf("%d", &case_n);
    for (int case_i = 1; case_i <= case_n; ++case_i) {
        printf("Case #%d: %d\n", case_i, solve());
    }
    return 0;
}

