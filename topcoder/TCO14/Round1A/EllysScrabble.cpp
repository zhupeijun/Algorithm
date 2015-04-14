#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))

int l[55], r[55], pos[55], vis[55];

class EllysScrabble {
public:
    string getMin(string str, int maxDis) {
        int n = str.size();
        for(int i = 0; i < n; i++) {
            l[i] = max(0, i - maxDis);
            r[i] = min(n - 1, i + maxDis);
            pos[i] = i;
        }
        for(int k = 0; k < n; k++) {
            int m = min(n - 1, k + maxDis);
            while(true) {
                bool more = false;
                for(int i =  k + 1; i <= m; i++) {
                    if(str[pos[i]] > str[pos[k]] || l[pos[i]] > k) continue;
                    if(str[pos[i]] == str[pos[k]] && pos[i] > pos[k]) continue;
                    for(int j = i - 1, cur = i; j >= k; j--) {
                        int x = pos[j], y = pos[cur];
                        if(l[x] <= cur && r[x] >= cur && l[y] <= j && r[y] >= j) {
                            swap(pos[cur], pos[j]);
                            cur = j;
                            if(cur == k) more = true;
                        }
                    }
                }
                if(!more) break;
            }
        }
        //for(int i = 0; i < n; i++) cout << pos[i] << endl;
        string ans = "";
        for(int i = 0; i < n; i++) ans.append(1, str[pos[i]]);
        return ans;
    }
};
