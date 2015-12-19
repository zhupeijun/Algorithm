#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

typedef long long ll;

class Procrastination {
public:
    long long findFinalAssignee(long long n) {
        if (n < 4) return n;
        for (int i = 2; i <= MAXN && i < n; ++i) {
            if (n % i == 0 && n > i) ++n;
            else if((n - 1) % i == 0 && n - 1 > i) --n;
        }
        if (n <= MAXN) return n;
        ll c = MAXN;
        for (int i = MAXN; i >= 2; --i) {
            if (n % i == 0) {
                ll k = n / i;
                if (k > c) { ++n; c = k; }
            } else if ((n - 1) % i == 0) {
                ll k = (n - 1) / i;
                if (k > c) { --n; c = k; }
            }
        }
        return n;
    }
};
