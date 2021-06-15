#include <bits/stdc++.h>

using namespace std;

template<int mod> 
struct modint {
    const static int _mod = mod;
    int _v;

    // constructor
    modint(const modint& o) { _v = o._v; }
    modint(int v) { _v = v; }

    // operator
    modint& operator+=(const modint& rhs) { 
        _v = (_v + rhs._v) % _mod;
        return *this;
    }

    modint& operator-=(const modint& rhs) {
        _v = ((_v - rhs._v) % _mod + _mod) % _mod; 
        return *this;
    }

    modint& operator*=(const modint& rhs) {
        _v = (int)(((long long)_v * rhs._v) % _mod);
        return *this;
    }

    modint& operator/=(const modint& rhs) {
        return *this = *this * rhs.inv();
    }

    modint pow(int n) const {
        modint x = *this, ret = 1;
        while (n) {
            if (n & 1) ret *= x;
            x *= x;
            n >>= 1;
        }
        return ret;
    }

    modint inv() const { 
        return pow(_mod - 2); 
    }
    
    friend modint operator+(const modint& a, const modint& b) {
        return modint(a)+=b;
    }

    friend modint operator-(const modint& a, const modint& b) {
        return modint(a)-=b;
    }

    friend modint operator*(const modint& a, const modint& b) {
        return modint(a)*=b;
    }

    friend modint operator/(const modint& a, const modint& b) {
        return modint(a)/=b;
    }

    friend bool operator==(const modint& a, const modint& b) {
        return a._v == b._v;
    }

    friend bool operator!=(const modint& a, const modint& b) {
        return a._v != b._v;
    }

    friend ostream& operator<<(ostream& out, const modint& rhs) {
        out << rhs.val();
        return out;
    } 

    int val() const {
        return _v;
    }
};

using mt = modint<11>;

int main() {
    assert(mt(5)  + mt(10) == mt(4) );
    assert(mt(5)  - mt(10) == mt(6) );
    assert(mt(5)  * mt(10) == mt(6) );
    assert(mt(10) / mt(5)  == mt(2) );
    return 0;
}