#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


class SelfDescFind {
public:
    bool check(string& str) {
        int cnt[10];
        memset(cnt, 0, sizeof(cnt));
        int len = str.size();
        for (int i = 0; i < len; ++i) {
            ++cnt[str[i] - '0'];
        }
        
        for (int i = 0; i < len; i += 2) {
            if (cnt[str[i + 1] - '0'] != (str[i] - '0')) {
                return false;
            }
        }
        return true;
    }
    
    string pack(vector<string>& strs) {
        string ret;
        int len = strs.size();
        sort(strs.begin(), strs.end());
        for (int i = 0; i < len; ++i) {
            ret += strs[i];
        }
        return ret;
    }
    
    
    void dfs(vector<int>& d, vector<string> buf, string& res, int max) {
        int dn = d.size();
        string tmp = pack(buf);
        if (max < 0) return;
        if (buf.size() >= dn) {
            if (check(tmp)) {
                if (res.empty() || res > tmp) {
                    res = tmp;
                }
            }
            return;
        }
        
        for (int i = 0; i < dn; ++i) {
            int cnt = d[i];
            int idx = buf.size();
            if (cnt == 0) continue;
            string tmp;
            tmp += (cnt + '0');
            tmp += (d[idx] + '0');
            buf.push_back(tmp);
            dfs(d, buf, res, max - cnt + 1);
            buf.pop_back();
        }
    }
    string construct(vector <int> digits) {
        string res;
        vector<string> buf;
        dfs(digits, buf, res, digits.size());
        return res;
    }
};



//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
