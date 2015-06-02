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

typedef long long LL;

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int sum = m;
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            sum += x;
        }
        if(sum % n == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

