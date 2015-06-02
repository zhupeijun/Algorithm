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

typedef long long ll;

using namespace std;

int b[10005];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, sum = 0, cnt = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            sum += b[i];
            if(b[i] != 0) cnt++;
        }
        if(sum < 100 || sum - 100 >= cnt) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

