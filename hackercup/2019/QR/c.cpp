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

char e[305];

int value(int x, char c) {
    if (c == 'x') return x;
    else if (c == 'X') return x ^ 1;
    else return c - '0';
}

int cal(int a, int b, char op) {
    if (op == '|') return a | b;
    else if (op == '&') return a & b;
    else return a ^ b;
}

int calExp(int x) {
    int n = strlen(e);
    stack<char> buf;
    for (int i = 0; i < n; ++i) {
        if (e[i] == ')') {
            int b = value(x, buf.top()); buf.pop();
            char op = buf.top(); buf.pop();
            int a = value(x, buf.top()); buf.pop();
            buf.pop(); // pop left brac
            buf.push(cal(a, b, op) + '0');
        } else {
            buf.push(e[i]);
        }
    }
    return value(x, buf.top());
}

void solve() {
    scanf("%s", e);
    printf("%d\n", calExp(0) == calExp(1) ? 0 : 1);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

