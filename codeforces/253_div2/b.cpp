#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int n, i, k, l, an, ans = 0;
    cin >> s; cin >> an;
    s.append(an, '$');
    n = s.size();
    for(i = 0; i < n; i++) {
        for(l = 1; l <= n; l++) {
            int m = i + l;
            if(i + l + l > n) continue;
            for(k = i; k < m; k++) 
                if(s[k] != '$' && s[k + l] != '$' && s[k] != s[k + l]) 
                    break;
            if(k == m) ans = max(ans, l * 2);
        }
    }
    cout << ans << endl;
    return 0;
}
