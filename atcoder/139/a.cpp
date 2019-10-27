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

char s[4];
char t[4];

int main() {
    scanf("%s", s);
    scanf("%s", t);

    int n = strlen(s);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == t[i]) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

