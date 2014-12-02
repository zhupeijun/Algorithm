#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 30005;

int a[N], b[N], vit[N], p[N];
vector< vector<int> > cirs;
vector<int> ans;

int main () {
    int n, i, m, j, cnt;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i]; p[a[i]] = i;
    }
    scanf("%d", &m);
    // get circle
    memset(vit, 0, sizeof(vit)); cnt = 0;
    for(i = 1; i <= n; i++) {
        if(vit[i] == 1 || a[i] == i) continue;
        vector<int> cir;
        int k = i;
        while(vit[k] == 0) {
            vit[k] = 1;
            cir.push_back(k);
            k = a[k];
        }
        cirs.push_back(cir);
        cnt += cir.size() - 1;
    }
    if(cnt == m) {
        printf("0\n");
        return 0;
    } else if(cnt > m) {
        int det = cnt - m;
        while(det > 0) {
            for(i = 1; i <= n; i++) {
                if(a[i] == i) continue;
                int k = a[i], min1 = i, min2 = 1000005;
                while(k != i) {
                    if(k < min1) { min2 = min(min1, min2); min1 = k; }
                    else {
                        if(k < min2) min2 = k;
                    }
                    k = a[k];
                }

                int t1 = min1;
                int t2 = min2;
                swap(a[t1], a[t2]);
                det --;
                ans.push_back(t1);
                ans.push_back(t2);
                break;
            }
        }
    } else {
        int det = m - cnt;
        memset(vit, 0, sizeof(vit));
        for(i = 1;det > 0 &&  i <= n;i++) {
            if(vit[i] == 1) continue;
            int k = i;
            while(vit[k] == 0) {
                vit[k] = 1;
                k = a[k];
            }
            if(i != 1) {
                ans.push_back(1);
                ans.push_back(i);
                det --;
            }
        }
    }
    int an = ans.size();
    printf("%d\n", an / 2);
    for(i = 0; i < an; i++) {
        printf("%d", ans[i]);
        if(i == an - 1) printf("\n");
        else printf(" ");
    }
    return 0;
}
