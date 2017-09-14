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

int p[100005];

int main() {
    int N;
    scanf ("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf ("%d", &p[i]);
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (p[i] == i + 1) {
            if (i + 1 < N) swap (p[i], p[i + 1]);
            ++cnt;
        }
    }
    printf ("%d\n", cnt);
    return 0;
}

