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

const int N = 100005;
int a[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int st = 0;
    for(int k = 0; k < m; k++) {
        char c[2];
        int ut;
        scanf("%s %d", c, &ut);
        if(c[0] == 'C') st = (st + ut) % n;
        else if(c[0] == 'A') st = (st - ut + n) % n;
        else printf("%d\n", a[(st + ut - 1 + n) % n]);
    }
    return 0;
}

