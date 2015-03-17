#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

int dp[105];

class CountryGroupHard {
public:
    string solve(vector <int> a) {
        int n = a.size();
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            if(dp[i] == 0) continue;
            for(int len = 1; i + len - 1 < n; len++) {
                bool ok = true;
                for(int j = i; j < i + len; j++) {
                    if(a[j] != 0 && a[j] != len) { ok = false; break; }
                }
                if(ok) dp[i + len] += dp[i];
            }
        }
        if(dp[n] == 1) return "Sufficient";
        else return "Insufficient";
    }
};