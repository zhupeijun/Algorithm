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
    int t[5];
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &t[i]);
    }

    int min_time = INT_MAX;
    vector<int> idx = { 0, 1, 2, 3, 4 };
    do {
        int cur = 0;
        for (int i = 0; i < 5; ++i) {
            int k = idx[i];
            if (cur % 10 != 0) {
                cur = (cur + 10) / 10 * 10;
            }
            cur += t[idx[i]];
        }
        min_time = min(min_time, cur);
    } while (next_permutation(idx.begin(), idx.end()));
    printf("%d\n", min_time);
    return 0;
}

