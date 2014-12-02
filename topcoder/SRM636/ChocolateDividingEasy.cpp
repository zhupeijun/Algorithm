#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int sum[55][55];

class ChocolateDividingEasy {
public:
    int findBest(vector <string> cho) {
        int n = cho.size(), m = cho[0].size();
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                if(i == 0) sum[j][i] = (cho[i][j] - '0');
                else sum[j][i] = sum[j][i - 1] + (cho[i][j] - '0');
            }
        }
        int ans = -1;
        for(int r1 = 0; r1 < n; r1++) {
            for(int r2 = r1 + 1; r2 < n; r2++) {
                int a[9];
                memset(a, 0, sizeof(a));
                for(int c1 = 0; c1 < m; c1++) {
                    a[0] += sum[c1][r1];
                    a[1] += sum[c1][r2] - sum[c1][r1];
                    a[2] += sum[c1][n - 1] - sum[c1][r2];
                    int tmp = min(a[0], min(a[1], a[2]));
                    for(int t = 3; t < 9; t++) a[t] = 0;
                    for(int ci = c1 + 1; ci < m; ci++) {
                        a[6] += sum[ci][r1];
                        a[7] += sum[ci][r2] - sum[ci][r1];
                        a[8] += sum[ci][n - 1] - sum[ci][r2];
                    }
                    for(int c2 = c1 + 1; c2 < m; c2++) {
                        int minv = tmp;
                        a[3] += sum[c2][r1];
                        a[4] += sum[c2][r2] - sum[c2][r1];
                        a[5] += sum[c2][n - 1] - sum[c2][r2];
                        minv = min(minv, min(a[3], min(a[4], a[5])));
                        minv = min(minv, min(a[6] - a[3], min(a[7] - a[4], a[8] - a[5])));
                        if(minv > ans) ans = minv;
                    }
                }
            }
        }
        return ans;
    }
};