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

bool check(int k, int n) {
    int i, j;
    for(i = 0, j = n - 1; i < j; i++, j--) {
        if(k == i) i++;
        if(k == j) j--;
        if(s[i] == s[j]) continue;
        else break;
    }
    return i >= j;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        int n = strlen(s), i, j;
        bool ans = false;
        for(i = 0, j = n - 1; i < j; i++, j--) {
            if(s[i] == s[j]) continue;
            else {
                if(check(i, n) || check(j, n)) ans = true;
                else break;
            }
        }
        if(i >= j) ans = true;
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}

