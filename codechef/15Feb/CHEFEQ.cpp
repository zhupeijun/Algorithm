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

const int N = 100005;
int a[N];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int maxv = 0, cur = 1;
        for(int i = 1; i < n; i++) {
            if(a[i] != a[i - 1]) cur = 1;
            else cur++;
            maxv = max(cur, maxv);
        }
        printf("%d\n", n - maxv);
    }
    return 0;
}

