#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

typedef long long LL;

using namespace std;

int w[26];

int main() {
    int i, k, maxv, maxi;
    string s;
    LL ans = 0;
    cin >> s;
    cin >> k;
    maxv =  maxi = -1;
    for(i = 0; i < 26; i++) {
        scanf("%d", &w[i]);
        if(w[i] > maxv) {
            maxv = w[i];
            maxi = i;
        }
    }
    int n = s.size();
    int m = n + k;
    for(i = 0; i < m; i++) {
        if(i < n) ans += 1LL * w[s[i] - 'a'] * (i + 1);
        else ans += 1LL * maxv * (i + 1);
    }
    cout << ans << endl;
    return 0;
}

