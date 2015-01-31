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


int b[105];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int maxv = 0, minv = 105;
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        maxv = max(maxv, b[i]);
        minv = min(minv, b[i]);
    }
    if(maxv - minv > k) printf("NO\n");
    else {
        printf("YES\n");
        for(int i = 0; i < n; i++) {
            int cur = 1;
            for(int j = 0; j < b[i]; j++) {
                if(j < minv + 1) printf("%d", cur);
                else {
                    cur++;
                    printf("%d", cur);
                }
                if(j == b[i] - 1) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}

