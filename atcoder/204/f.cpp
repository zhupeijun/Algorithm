#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define rrep(i, n) for (int i=0; i<=(n); ++i)
#define each(v, i) for (auto i : v) 
#define pb push_back
#define sz (int)(x).size()
#define fi first
#define se second
#define maxs(x, y) x = max(x, y)
#define mins(x, y) x = min(x, y)
#define pcnt __builtin_popcount
#define rng(a) a.begin(), a.end()

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;
using vvi = vv<int>;

template<int mod> 
struct modint {
    const static int _mod = mod;
    int _v;

    // constructor
    modint() { _v = 0; }
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

using mt = modint<998244353>;
using mat = vc<vc<mt>>;

ll H, W, M;

const mt sel[7] = {1,1,2,3,5,8,13};

mt calt(int x) {
    mt ret = 1;
    int len = 0;
    rep(i, H+1) {
        if (i == H || x>>i&1) {
            if (len > 0) ret *= sel[len];
            len = 0;
        } else {
            ++len;
        }
    }
    return ret;
}

mt cal(int x, int y) {
    if (x&y) return 0;
    return calt(x|y);
}

mat init() {
    mat res(M, vc<mt>(M));
    rep(i, M) {
        rep(j, M) {
            res[i][j] = cal(i, j);
        }
    }
    return res;
}

mat mul(mat a, mat b) {
    mat res(M, vc<mt>(M));
    rep(i, M) {
        rep(j, M) {
            rep(k, M) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

vc<mt> mul(vc<mt> a, mat b) {
    vc<mt> ret(M);
    rep(i, M) {
        rep(j, M) {
            ret[i] += a[j] * b[j][i];
        }
    }
    return ret;
}

mat pow(mat x, ll n) {
    mat res(M, vc<mt>(M));
    rep(i, M) res[i][i] = 1;
    while (n) {
        if (n&1) res = mul(res, x);
        x = mul(x,x);
        n >>= 1;
    }
    return res;
}

int main() {
    cin >> H >> W;
    M = 1<<H;
    init();
    vc<mt> c(M); c[M-1] = 1;
    mat t = init();

    mat y = pow(t, 1);
    c = mul(c, pow(t, W));
    mt ans = 0;
    rep(i, M) ans += c[i] * calt(i);
    cout << ans << endl;
    return 0;
}