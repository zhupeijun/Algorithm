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

int press(int& a, int& b) {
    int coin;
    if (a > b) {
        coin = a;
        --a;
    } else {
        coin = b;
        --b;
    }
    return coin;
}

int main() {
    int a, b;
    scanf ("%d %d", &a, &b);
    int total = 0;
    total += press(a, b);
    total += press(a, b);
    printf("%d\n", total);
    return 0;
}

