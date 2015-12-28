#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

class DoubleOrOneEasy {
public:
    int minimalSteps(int a, int b, int newA, int newB) {
        if (newA < a || newB < b) return -1;
        if (a > b) { swap(a, b); swap(newA, newB); }
        ll da = newA - a, db = newB - b;
        if (da > db) return -1;
        ll r = 0, n2 = 0;
        if (b - a == 0) {
            if (newA != newB) return -1;
            else {
                while(a * 2 <= newA) {
                    a *= 2; ++n2;
                }
                r = newA - a;
            }
        } else {
            ll s = b - a;
            if ((newB - newA) % s != 0) return -1;
            ll t = (newB - newA) / s;
            if (a * t > newA || b * t > newB) return -1;
            ll x = t;
            while(x) {
                if (x & 1) {
                    if ((x >> 1) != 0) return -1;
                }
                x >>= 1;
                ++n2;
            }
            --n2;
            r = newA - a * t;
        }
        int ans = 0;
        for (int k = n2; k >= 0; --k) {
            ll base = 1 << k;
            ans += r / base;
            r -= r / base * base;
        }
        return ans + n2;
    }
};
