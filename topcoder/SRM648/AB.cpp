#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class AB {
public:
    string createString(int N, int K) {
        int maxn = (N / 2) * (N - (N / 2));
        if(K > maxn) return "";
        string ans = "";
        ans.append(N, 'B');
        int an = 0, cur = -1;
        for(int k = 0; k < K; k++) {
            if(cur - 1 < 0 || ans[cur - 1] == 'A') {
                cur = N - an - 2;
                an++;
                ans[cur] = 'A';
            } else {
                swap(ans[cur], ans[cur - 1]);
                cur = cur - 1;
            }
        }
        return ans;
    }
};