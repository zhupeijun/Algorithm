#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class PotentialArithmeticSequence {
public:
    int numberOfSubsequences(vector <int> d) {
        int n = d.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int cur = 0;
                bool ok = true;
                for(int k = i; k <= j; k++) {
                    cur += 1;
                    int x = cur, cnt = 0, first = -1;
                    while(x) {
                        if(first == -1 && (x & 1)) first = cnt;
                        cnt++; x >>= 1;
                    }
                    if(cur == (1 << (cnt - 1))) {
                        if(d[k] >= 7) cur = (1 << 6);
                        else {
                            if(d[k] >= cnt - 1) cur = (1 << d[k]);
                            else {
                                if(first != d[k]) { ok = false; break; }
                            }    
                        }
                    } else {
                        if(first != d[k]) { ok = false; break; }
                    }
                }
                if(ok) ans++;
            }
        }
        return ans;
    }
};