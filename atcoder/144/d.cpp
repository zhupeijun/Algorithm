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
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const double PI = 3.141592653589793;
double h, a, x;

double getMaxWater(double degree) {
    double d = PI / 180 * degree;
    double t = tan(d);
    double p1 = t * h;
    double s1 = h * p1 * 0.5;
    if (p1 > a) {
        double p3 = p1 - a;
        double p4 = p3 / t;
        double s2 = p3 * p4 * 0.5;
        s1 -= s2;
    }
    return s1 * a;
}

int main() {
    scanf("%lf %lf %lf", &a, &h, &x);
    double left = 0, right = 90;
    while (abs(right - left) > 0.00000001) {
        double mid = (left + right) / 2;
        double c = getMaxWater(mid);
        if (c > x) {
            right = mid;
        } else {
            left = mid;
        }
    }
    printf("%.9lf\n", 90.0 - left);
    return 0;
}

