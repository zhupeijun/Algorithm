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

int a[N], b[N], c[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n - 1; i++) scanf("%d", &b[i]);
    for(int i = 0; i < n - 2; i++) scanf("%d", &c[i]);
    sort(a, a + n);
    sort(b, b + n - 1);
    sort(c, c + n - 2);

    int fst = a[n - 1], sec = b[n - 2];
    for(int i = 0; i < n - 1; i++) {
        if(a[i] != b[i]) { fst = a[i]; break; }
    }
    for(int i = 0; i < n - 2; i++) {
        if(b[i] != c[i]) { sec = b[i]; break; }
    }
    printf("%d\n%d\n", fst, sec);
    return 0;
}

