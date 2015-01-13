#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

class AliceGame {
public:
    long long findMinimumValue(long long x, long long y) {
        if(x == 2 || y == 2) return -1L;
        if(x == 0) return 0L;
        ll sum = x + y;
        ll t = sqrt(sum);
        if(t * t != sum) return -1L;
        if(y == 0) return t;
        ll maxv = 1 + (t - 1) * 2;
        if(x <= maxv) return (x & 1) ? 1L : 2L;
        ll l, r, m;
        l = 1, r = t; 
        while(l <= r) {
            m = (l + r) / 2;
            if(sum - m * m >= x) l = m + 1;
            else r = m - 1;
        }
        ll tail = sum - (l - 1) * (l - 1);
        if((tail & 1) == (x & 1))
            return (t - l + 1);
        else return (t - l + 2);    
    }
};