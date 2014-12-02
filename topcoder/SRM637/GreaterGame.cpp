#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int exist[105];

class GreaterGame {
public:
    double calc(vector <int> hand, vector <int> sothe) {
        int n = hand.size();
        vector<int> unknow, known, remained;        
        memset(exist, 0, sizeof(exist));
        for(int i = 0; i < n; i++) {
            exist[hand[i]] = 1;
            if(sothe[i] != -1) {
                exist[sothe[i]] = 1;
                known.push_back(sothe[i]);
            }
        }
        
        int an = n * 2; 
        double ans = 0;
        for(int i = 1; i <= an; i++) if(!exist[i]) unknow.push_back(i);    
        sort(hand.begin(), hand.end());
        sort(known.begin(), known.end());
        int kn = known.size();
        for(int i = 0, j = 0; i < n; i++) {
            if(j < kn && hand[i] > known[j]) { j++; ans++; continue;}
            remained.push_back(hand[i]);
        }
        int un = unknow.size(), rn = remained.size();
        sort(unknow.begin(), unknow.end());
        for(int i = 0; i < un; i++) {
            int j;
            for(j = 0; j < un; j++)
                if(remained[rn - i - 1] < unknow[j]) break;
            ans += 1.0 * j / un;
        }
        return ans;
    }
};