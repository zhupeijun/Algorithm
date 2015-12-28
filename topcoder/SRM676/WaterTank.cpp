#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

const double EPS = 1e-9;

class WaterTank {
public:
    double minOutputRate(vector <int> t, vector <int> x, int C) {
        double l = 0, r = 10000005;
        int n = t.size();
        while(fabs(l - r) > EPS) {
            double mid = (l + r) / 2;
            double cur = 0;
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                double left = t[i] * (x[i] - mid);
                cur = max(0.0, cur + left);
                if (cur > C) { ok = false; break; }  
            }
            if (ok) r = mid;
            else l = mid;
        }
        return l;
    }
};
