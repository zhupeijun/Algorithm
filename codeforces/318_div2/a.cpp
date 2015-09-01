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

int a[1005];

int main() {
    int n;
    scanf("%d", &n);
    priority_queue<int> q;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i > 0) q.push(a[i]);
    }
    int b = a[0];
    while(true) {
        int t = q.top(); q.pop();
        if(t >= a[0]) { t--; a[0]++; q.push(t); }
        else break;
    }
    printf("%d\n", a[0] - b);
    return 0;
}

