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

int cnt[100005];

int main() {
    int N;
    scanf ("%d", &N);
    memset (cnt, 0, sizeof (cnt));
    int max_cnt = 0;
    for (int i = 0; i < N; ++i) {
        int x;
        scanf ("%d", &x);
        ++cnt[x]; ++cnt[x + 1]; ++cnt[x + 2];
        max_cnt = max(cnt[x], max(cnt[x + 1], max (cnt[x + 1], max_cnt)));
    }
    printf ("%d\n", max_cnt);
    return 0;
}

