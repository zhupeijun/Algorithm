#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

const int N = 405;
const double EPS = 1e-9;

double k[N], l[N];

class SimilarRatingGraph {
public:
    double maxLength(vector <int> dt, vector <int> rt) {
        int n = dt.size();
        for(int i = 1; i < n; i++) {
            double dx = dt[i] - dt[i - 1];
            double dy = rt[i] - rt[i - 1];
            k[i] = 1.0 * dy / dx;
            l[i] = sqrt(dx * dx + dy * dy);
        }
        double ans = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < n; j++) {
                if(i == j) continue;
                if(abs(k[i] - k[j]) < EPS) {
                    double zm = 1.0 * (dt[i] - dt[i - 1]) / (dt[j] - dt[j - 1]);
                    double tmp = 0; 
                     for(int t = 0; t + i < n && t + j < n; t++) {
                         if(abs(k[i + t] - k[j + t]) > EPS) break;
                        double idx = dt[i + t] - dt[i + t - 1];
                        double jdx = dt[j + t] - dt[j + t - 1];
                        if(abs(jdx * zm - idx) > EPS) break;
                        tmp += l[i + t];     
                    }
                    ans = max(ans, tmp);
                }    
            }
        }
        return ans;
    }
};