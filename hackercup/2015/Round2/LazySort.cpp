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

const int N = 50005;

int a[N];

bool check(int n, bool from_top) {
    int top, bot, ci, cj;
    bool ok = true;
    if(from_top) {
        bot = top = a[0];
        ci = 1; cj = n - 1;
    } else {
        bot = top = a[n - 1];
        ci = 0; cj = n - 2;
    }
    while(ci <= cj) {
        if(a[ci] == top - 1) {
            top = a[ci];
            ci++;
        } else if(a[ci] == bot + 1) {
            bot = a[ci];
            ci++;
        } else if(a[cj] == top - 1) {
            top = a[cj];
            cj--;
        } else if(a[cj] == bot + 1) {
            bot = a[cj];
            cj--;
        } else {
            ok = false;
            break;
        }
    }
    return ok;
}

int main() {
    freopen("lazy_sort_in.txt", "r", stdin);
    freopen("lazy_sort_out.txt", "w", stdout);
    int ci, cn;
    scanf("%d", &cn);
    for(ci = 1; ci <= cn; ci++) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("Case #%d: ", ci);
        if(check(n, true) || check(n, false)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

