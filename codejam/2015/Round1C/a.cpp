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

int main() {
    int cn;
    scanf("%d", &cn);
    for(int ci = 1; ci <= cn; ci++) {
        int r, c, w, ans = 0;
        scanf("%d %d %d", &r, &c, &w);
        for(int k = w; k <= c; k += w) {
            int res = w + k / w;
            if (k == c) res --;
            if(ans < res) ans = res;
        }
        printf("Case #%d: %d\n",ci, ans + c / w * (r - 1));
    }
    return 0;
}

