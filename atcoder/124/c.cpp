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
    scanf("%s", s);
    int n = strlen(s);
    int repaint0 = 0, repaint1 = 0;
    for (int i = 0; i < n; ++i) {
        int v = s[i] - '0';
        if ((i & 1) == v) {
            ++repaint1;
        } else {
            ++repaint0;
        }
    }
    printf("%d\n", min(repaint0, repaint1));
    return 0;
}

