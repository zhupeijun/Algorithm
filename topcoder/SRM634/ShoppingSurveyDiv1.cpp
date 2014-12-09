#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int MAXN = 505;
int tot[MAXN], top[MAXN];

class ShoppingSurveyDiv1 {
public:
    int minValue(int N, int K, vector <int> s) {
        int M = s.size();
        for(int k = 0; k <= N; k++) {
            vector<int> tmp = s;
            int can = 0;
            for(int i = 0; i < N; i++) { tot[i] = 0; top[i] = -1; }
            for(int i = 0; i < k; i++) {
                for(int j = 0; j < M; j++)
                    if(tmp[j] > 0) { tmp[j]--; tot[i]++; top[i] = j; }
                if(tot[i] >= K) can++;
            }
            bool ok = true;
            int ci = k;
            for(int j = 0; j < M; j++) {
                while(tmp[j] > 0) {
                    if(top[ci] == j) { ok = false; break; }
                    tot[ci] ++; top[ci] = j; tmp[j] --;
                    if(tot[ci] >= K) { ok = false; break; }
                    ci = (ci + 1) % N;
                    if(ci == 0) ci = k;
                }
                if(!ok) break;
            }
            if(ok) return can;
        }
        return N;
    }
};