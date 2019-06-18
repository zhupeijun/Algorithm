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

int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    int D = 0;
    int cnt = 1;
    for (int i = 0; i < N; ++i) {
        int L;
        scanf("%d", &L);
        D = D + L;
        if (D <= X) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

