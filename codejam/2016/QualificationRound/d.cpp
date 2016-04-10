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

void solve() {
    int K, C, S;
    scanf("%d %d %d", &K, &C, &S);
    for (int i = 1; i <= S; ++i) {
        if (i != 1) printf(" ");
        printf("%d", i);
    }
    printf("\n");
}

int main() {
    int case_n;
    scanf("%d", &case_n);
    for (int case_i = 1; case_i <= case_n; ++case_i) {
        printf("Case #%d: ", case_i);
        solve();
    }
    return 0;
}

