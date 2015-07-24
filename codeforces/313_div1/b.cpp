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

const int N = 200005;

char a[N], b[N];

string arrange(string s) {
    int n = s.size();
    if(n & 1) return s;
    else {
        int m = n / 2;
        string s1 = s.substr(0, m), s2 = s.substr(m, m);
        s1 = arrange(s1); s2 = arrange(s2);
        if (s1.compare(s2) <= 0) return s1 + s2;
        else return s2 + s1;
    }
}

int main() {
    scanf("%s", a);
    scanf("%s", b);
    const char *ans = arrange(a) == arrange(b) ? "YES" : "NO";
    printf("%s\n", ans);
    return 0;
}

