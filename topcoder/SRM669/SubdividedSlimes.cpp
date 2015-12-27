#include <iostream>
#include <cstring>

using namespace std;

class SubdividedSlimes {
public:
    int maxMascots(int S, int d) {
        int r = S % d, p = S / d;
        int total = 0;
        for (int i = 1; i < d; ++i) {
            if (r > d - i) total += (p + 1) * (p + 1) * (d - i);
            else total += p * (((p + 1) * r) + (d - r - i) * p);
        }
        return total;
    }
    int needCut(int S, int M) {
        for (int d = 1; d < S; ++d) {
            if (maxMascots(S, d + 1) >= M) return d;
        }
        return -1;
    }
};
