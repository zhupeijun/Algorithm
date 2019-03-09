#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

bool dp[2005][10];

class ReconstructNumber {
public:
    string smallest(string cmp) {
        int n = cmp.size();
        for (int j = 0; j < 10; ++j) {
            dp[n][j] = true;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    if (dp[i + 1][j] && satisfy(cmp[i], k, j)) {
                        dp[i][k] = true;
                    }
                }
            }
        }

        string ret = "";
        bool exist = false;
        for (int j = 1; j < 10; ++j) {
            if (dp[0][j]) {
                exist = true;
                ret += ('0' + j);
                break;
            }
        }

        if (!exist) {
            return "";
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (dp[i + 1][j] && satisfy(cmp[i], ret.back() - '0', j)) {
                    ret += ('0' + j);
                    break;
                }
            }
        }
        return ret;
    }

    bool satisfy(char c, int a, int b) {
        if (c == '>') return a > b;
        else if (c == '<') return a < b;
        else if (c == '=') return a == b;
        else return a != b;
    }
};
