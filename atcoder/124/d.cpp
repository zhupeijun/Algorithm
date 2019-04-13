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

char s[100005];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    scanf("%s", s);
    int cur = 0, res = 0, i = 0, j = 0, t = 0;
    while (i < N && j < N) {
        int k = j;
        while (k < N && s[j] == s[k]) ++k;
        cur += (k - j);
        if (s[j] == '0') {
            ++t;
            j = k;
            k = j;
            while (k < N && s[j] == s[k]) ++k;
            cur += (k - j);
            j = k;
        } else {
            j = k;
        }
        if (t > K) {
            k = i;
            while (k < N && s[i] == s[k]) ++k;
            cur -= (k - i);
            if (s[i] == '1') {
                i = k;
                k = i;
                while (k < N && s[i] == s[k]) ++k;
                cur -= (k - i);
                i = k;
            } else {
                i = k;
            }
        }
        res = max(res, cur);
    }
    printf("%d\n", res);
    return 0;
}

