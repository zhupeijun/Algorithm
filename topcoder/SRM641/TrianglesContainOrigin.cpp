#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

struct point {
    int x, y;
    
    point(int _x, int _y) {
        x = _x; y = _y;
    }
    
    int cross(const point &p) const {
        return x * p.y - p.x * y;
    }
    
    bool operator < (const point& p) const {
        if(y < 0 && p.y >= 0) return false;
        if(y >= 0 && p.y < 0) return true;
        return cross(p) > 0;
    }
};

class TrianglesContainOrigin {
public:
    int find(const vector<point> & ps, point p) {
        int l = 0, r = ps.size() - 1, mid;
        while(l <= r) {
            mid = (l + r) / 2;
            if(ps[mid] < p) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
    
    long long count(vector <int> x, vector <int> y) {
        int n = x.size();
        vector<point> ps;
        for(int i = 0; i < n; i++)
            ps.push_back(point(x[i], y[i]));
        sort(ps.begin(), ps.end());
        
        ll ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                point p1 = point(-ps[i].x, -ps[i].y);
                point p2 = point(-ps[j].x, -ps[j].y);
                
                int k1 = find(ps, p1);
                int k2 = find(ps, p2);
                
                if(p1.cross(p2) > 0) {
                    if(k2 >= k1) ans += k2 - k1;
                    else ans += n - k1 + k2;
                } else {
                    if(k2 > k1) ans += n - k2 + k1;
                    else ans += k1 - k2;
                }
            }
        }
        return ans / 3;
    }
};