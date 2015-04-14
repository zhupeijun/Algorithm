#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class EllysSortingTrimmer {
public:
    string getMin(string S, int L) {
        int n = S.size();
        priority_queue<char> q;
        for(int i = n - 1; i >= 0; i--) {
            if(q.size() >= L) q.pop();
            q.push(S[i]);
        }
        string ans = "";
        while(!q.empty()) { ans.append(1, q.top()); q.pop(); }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
