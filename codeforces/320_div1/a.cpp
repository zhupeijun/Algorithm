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

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    double ans = a < b ? -1 : (a + b) * 0.5 / ((a + b) / (b * 2));
    printf("%.12lf\n", ans);
    return 0;
}

