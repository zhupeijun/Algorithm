#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

vector<string> xy,yz,zx;
int cubs[12][12][12], n;
int d[6][3] = { 
    {1, 0, 0}, 
    {0, 1, 0}, 
    {0, 0, 1}, 
    {-1, 0, 0},
    {0, -1, 0},
    {0, 0, -1}
};

class ShadowSculpture {
public:
    bool isOpt(int i, int j, int k) {
        if(xy[i][j] == 'N' || yz[j][k] == 'N' || zx[k][i] == 'N') return false;
        return true;
    }
    void dfs(int i, int j, int k) {
        if(cubs[i][j][k] >= 0) return ;
        if(isOpt(i, j, k)) {
            cubs[i][j][k] = 1;
            for(int t = 0; t < 6; t++) {
                int di = i + d[t][0];
                int dj = j + d[t][1];
                int dk = k + d[t][2];
                if(di >= 0 && di < n && dj >= 0 && dj < n && dk >= 0 && dk < n)
                    dfs(di, dj, dk);
            }
        } else {
            cubs[i][j][k] = 0;
        }
    }
    bool check_dim(vector<int> ar, char c) {
        int m = ar.size();
        bool is = true;
        for(int i = 0; i < m; i++)
            if(ar[i] == 1) { is = false; break; }
        if(c == 'Y' && is) return false;
        return true;
    }
    
    bool check() {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                //test for xy
                vector<int> z;
                for(int k = 0; k < n; k++) z.push_back(cubs[i][j][k]);
                if(!check_dim(z, xy[i][j])) return false;
                //test for yz
                vector<int> x;
                for(int k = 0; k < n; k++) x.push_back(cubs[k][i][j]);
                if(!check_dim(x, yz[i][j])) return false;
                //test for zx
                vector<int> y;
                for(int k = 0; k < n; k++) y.push_back(cubs[j][k][i]);
                if(!check_dim(y, zx[i][j])) return false;
            }
        return true;
    }
    string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
        xy = XY; yz = YZ; zx = ZX;
        n = xy.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    memset(cubs, -1, sizeof(cubs));
                    dfs(i, j, k);
                    if(check()) return "Possible";
                }
            }
        }
        return "Impossible";
    }
};