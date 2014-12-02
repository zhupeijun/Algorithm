#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100005;

int d[N], mk[10];

int main() {
    string s;
    int n, i, k;
    cin >> s;
    n = s.size();
    for(i = 0; i < n; i++) d[i] = -1;
    for(i = 0; i < 10; i++) mk[i] = 0;
    k = 0; d[0] = 0; mk[s[0] - '0'] = 1;
    while(1) {
        k++;
        bool ok = true;
        vector<int> tmp;
        for(i = 0; i < n; i++) {
            if(d[i] == -1) {
                int t = s[i] - '0';
                if(mk[t] == 1 || (i + 1 < n && d[i + 1] != -1) 
                    || (i - 1 >= 0 && d[i - 1] != -1)) {
                    tmp.push_back(i);
                }
                ok = false;
            }
        }
        int m = tmp.size();
        for(i = 0; i < m; i++) {
            int t = s[tmp[i]] - '0';
            d[tmp[i]] = k;
            mk[t] = 1;
        }
        if(ok) break;
    }
    cout << d[n - 1] << endl;
    return 0;
}
