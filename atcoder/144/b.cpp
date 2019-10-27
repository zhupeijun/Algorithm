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

int main() {
    vector<bool> good(100, false);
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            good[i * j] = true;
        }
    }
    int n;
    scanf("%d", &n);
    printf("%s\n", good[n] ? "Yes" : "No");
    return 0;
}

