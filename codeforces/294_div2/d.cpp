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

typedef long long ll;
typedef pair<int, int> pii;

const int N = 100005;

map<ll, int> M;
int x[26];
ll sum[N];
char str[N];

int main() {
    for(int i = 0; i< 26; i++) scanf("%d", &x[i]);
    scanf("%s", str);
    int n = strlen(str);
    for(int i = 0; i < n; i++) {
        int idx = str[i] - 'a';
        if (i == 0) sum[i] = x[idx];
        else sum[i] = sum[i - 1] + x[idx];
        if (i < n - 1) {
            ll key = sum[i] * 100 + (str[i + 1] - 'a');
            if (M.find(key) == M.end()) M[key] = 1;
            else M[key]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int idx = str[i] - 'a';
        ll key = sum[i] * 100 + idx;
        if (M.find(key) != M.end()) {
            ans += M[key];
        }
        if (i < n - 1) {
            key = sum[i] * 100 + (str[i + 1] - 'a');
            if(M.find(key) != M.end()) M[key]--;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}

