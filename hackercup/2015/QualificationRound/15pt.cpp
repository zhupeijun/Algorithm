#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> split(int x) {
    vector<int> res;
    while(x) { res.push_back(x % 10); x /= 10; }
    return res;
}

int swaped_value(vector<int> ar, int x, int y) {
    swap(ar[x], ar[y]);
    int res = 0, n = ar.size();
    for(int i = n - 1; i >= 0; i--) {
        res = res * 10 + ar[i];
    }
    return res;
}

int main() {
    freopen("15pt_input.txt", "r", stdin);
    freopen("15pt_output.txt", "w", stdout);
    int cn, ci;
    scanf("%d", &cn);
    for(ci = 0; ci < cn; ci++) {
        int x;
        scanf("%d", &x);
        vector<int> ar = split(x);
        int n = ar.size();
        int maxv = x, minv = x;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if((i == n - 1 && ar[j] == 0) || (j == n - 1 && ar[i] == 0))
                    continue;
                int res = swaped_value(ar, i, j);
                if(res > maxv) maxv = res;
                if(res < minv) minv = res;
            }
        }
        printf("Case #%d: %d %d\n", ci + 1, minv, maxv);
    }
    return 0;
}

