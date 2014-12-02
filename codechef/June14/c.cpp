#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int N = 100;

map<char, char> M;

int main() {
    int ci, cn, n;

    cin >> cn;
    for(ci = 0; ci < cn; ci ++) {
        M.clear();
        cin >> n;
        int i, m, d, l, r;
        char k, v;
        string s;
        for(i = 0; i < n; i++) {
            cin >> k >> v;
            M[k] = v;
        }
        cin >> s;
        m = s.size();
        //sub
        for(i = 0; i < m; i++) 
            if(M.find(s[i]) != M.end()) 
                s[i] = M[s[i]];
        //find
        for(d = 0; d < m; d++) if(s[d] == '.') break;
        for(l = 0; l < d; l++) if(s[l] != '0') break;
        for(r = m - 1; r > d; r--) if(s[r] != '0') break;

        if(d == m) {
            if(l == m) cout << "0" << endl;
            else cout << s.substr( l, m - l) << endl;
        } else {
            if(l == d && r == d) cout << "0" << endl;
            else {
                if(l == d) cout << s.substr( l, r - l + 1) << endl;
                else if(r == d) cout << s.substr(l, d - l) << endl;
                else cout << s.substr(l , r - l + 1) << endl;
            }
        }
    }
    return 0;
}
