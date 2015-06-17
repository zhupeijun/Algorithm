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

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int N = 100005;

struct point {
    double x, y;
    point(double _x, double _y) { x = _x; y = _y; }
};

struct polygon {
    int idx;
    double area;
    polygon(int _idx, double _area) { idx = _idx; area = _area; }
    bool operator < (polygon other) const {
        return area < other.area;
    }
};

int ans[N];

double det(point a, point b, point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<polygon> polys;
        for(int i = 0; i < n; i++) {
            int m;
            scanf("%d", &m);
            vector<point> poly;
            for(int j = 0; j < m; j++) {
                int x, y;
                scanf("%d %d", &x, &y);
                poly.pb(point(x, y));
            }
            double area = 0;
            for(int j = 1; j < m - 1; j++) {
                area += det(poly[0], poly[j + 1], poly[j]) * 0.5;
            }
            polys.pb(polygon(i, abs(area)));
        }
        sort(polys.begin(), polys.end());
        for(int i = 0; i < n; i++) {
            ans[polys[i].idx] = i;
        }
        for(int i = 0; i < n; i++) {
            printf("%d", ans[i]);
            if(i == n - 1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}

