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

int a[6];

int main() {
    for(int i = 0; i < 6; i++) scanf("%d", &a[i]);
    int len = a[2] + a[3] + a[4];
    int ans = len * len - a[0] * a[0] - a[2] * a[2] - a[4] * a[4];
    printf("%d\n", ans);
    return 0;
}

