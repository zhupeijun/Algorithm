#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class TheTips {
public:
    double solve(vector <string> c, vector <int> p) {
        int n = c.size();
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(c[i][k] == 'Y' && c[k][j] == 'Y')
                        c[i][j] = 'Y';
        double ans = 0;
        for(int i = 0; i < n; i++) {
            double np = 1;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(c[j][i] == 'Y')
                    np *= (100.0 - p[j]) / 100.0;
            }
            ans += (1 - np) + (np * p[i] / 100.0);
        }
        return ans;
    }
};
