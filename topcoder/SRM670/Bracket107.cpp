#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))

const int M = 55;

int dp[M][M][M];

class Bracket107 {
public:
    bool check(string s) {
        int n = s.size(), ln = 0, rn = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') ++ln;
            else ++rn;
            if (rn > ln) return false;
        }
        return true;
    }
    int yetanother(string s) {
        set<string> res;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            string t1 = s;
            char c = t1[i];
            t1.erase(t1.begin() + i);
            for (int j = 0; j < n; ++j) {
                string t2 = t1;
                t2.insert(t2.begin() + j, c);
                if (check(t2)) {
                    res.insert(t2);
                }
            }
        }
        return res.size() - 1;
    }
};
