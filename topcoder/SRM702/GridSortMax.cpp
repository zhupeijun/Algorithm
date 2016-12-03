#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int g[55][55];
bool fx[55], fy[55];
int n, m;

class GridSortMax {
public:
    void find(int k, int &x, int &y) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == k) {
                    x = i; y = j;
                    return;
                }
            }
        }
    }
    string findMax(int N, int M, vector <int> grid) {
        n = N; m = M;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                g[i][j] = grid[i * m + j] - 1;
            }
        }
        memset(fx, false, sizeof(fx));
        memset(fy, false, sizeof(fy));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = 0, y = 0;
                find(i * m + j, x, y);
                if (i == x && j == y) {
                    fx[i] = fy[j] = true;
                } else if (i == x) {
                    if (!fy[j] && !fy[y]) {
                        for (int k = 0; k < n; ++k) swap(g[k][j], g[k][y]);
                        fx[i] = fy[j] = true;
                    }
                } else if (j == y) {
                    if (!fx[i] && !fx[x]) {
                        for (int k = 0; k < m; ++k) swap(g[i][k], g[x][k]);
                        fx[i] = fy[j] = true;
                    }
                } else if (!fx[i] && !fy[j] && !fx[x] && !fy[y]) {
                    for (int k = 0; k < m; ++k) swap(g[i][k], g[x][k]);
                    for (int k = 0; k < n; ++k) swap(g[k][j], g[k][y]);
                    fx[i] = fy[j] = true;
                }
            }
        }
        string ans = "";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] != i * m + j) ans += "0";
                else ans += "1";
            }
        }
        return ans;
    }
};
