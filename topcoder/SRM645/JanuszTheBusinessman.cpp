#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int INF = 1005;

int f[55][55]; 

struct node {
    int x, y;
    node(int _x, int _y) {
        x = _x; y = _y;
    }
    bool operator < (const node & a) const { 
        if(y == a.y) return x < a.x;
        else return y < a.y;
    }
};

class JanuszTheBusinessman {
public:
    int makeGuestsReturn(vi ar, vi de) {
        int n = ar.size();
        vector<node> vn;
        for(int i = 0; i < n; i++)
            vn.push_back(node(ar[i], de[i]));
        sort(vn.begin(), vn.end());
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                f[i][j] = INF;
        for(int i = 0; i < n; i++) {
            if(i == 0) f[i][i] = 1;
            else {
                int idx = -1, minv = INF;
                for(int j = 0; j < i; j++) {
                    if(vn[i].x <= vn[j].y) f[i][j] = f[i - 1][j];
                    if(vn[i].x > vn[j].y) idx = j;
                }
                if(idx == -1) minv = 0;
                else {
                    for(int j = idx; j < i; j++)
                        for(int k = 0; k <= j; k++)
                            minv = min(f[j][k], minv);
                }
                f[i][i] = minv + 1;
            }
        }
        int ans = INF;
        for(int i = 0; i < n; i++) ans = min(ans, f[n - 1][i]);
        return ans;
    }
};