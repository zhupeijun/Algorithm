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

int main() {
    int n, maxv, maxi;
    scanf("%d", &n);
    maxv = 0;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if(x > maxv)
            maxv = x;
    }
    printf("%d\n", maxv);
    return 0;
}

