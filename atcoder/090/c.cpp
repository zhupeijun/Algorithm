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
#include <climits>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, b) FOR(i, 0, b)

typedef long long ll;
typedef pair<int, int> pii;

const int MAX_N = 105;

int grid[2][MAX_N], sum1[MAX_N], sum2[MAX_N];

int main() {
    int N;
    scanf ("%d", &N);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf ("%d", &grid[i][j]);
        }
    }

    memset(sum1, 0, sizeof(sum1));
    memset(sum2, 0, sizeof(sum2));
    for (int i = 0; i < N; ++i) {
        sum1[i] = i > 0 ? sum1[i - 1] + grid[0][i] : grid[0][i];
        sum2[i] = i > 0 ? sum2[i - 1] + grid[1][i] : grid[1][i];
    }

    int max_value = 0;
    for (int i = 0; i < N; ++i) {
        int sum2_right = sum2[N - 1] - (i > 0 ? sum2[i - 1] : 0);
        max_value = max(max_value, sum1[i] + sum2_right);
    }

    printf ("%d\n", max_value);
    return 0;
}

