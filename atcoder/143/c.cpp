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
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char s[100005];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && s[i] != s[i - 1]) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

