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

typedef long long LL;

using namespace std;

const int N = 100005;
char s[N];
bool exist[26];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        memset(exist, false, sizeof(exist));
        int n = strlen(s), ans = 0;
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (!exist[idx]) {
                ans++;
                exist[idx] = true;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

