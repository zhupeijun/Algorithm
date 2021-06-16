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
    modint(int v) { _v = ((v%_mod)+_mod)%_mod; }

    // operator
    modint& operator+=(const modint& rhs) { 
        _v = ((_v + rhs._v) % _mod + _mod) % _mod;
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

using mint = modint<1000000007>;

const int M = 100005;
mint fib[M];

void init() {
    rep(i, M) {
        if (i <= 3) fib[i] = i;
        else fib[i] = fib[i-1] + fib[i-2];
    }
}

mint get(int len) {
    return fib[max(1, len)];
}

int main() {
    int N; cin >> N;
    vi a(N); rep(i, N) cin >> a[i];
    init();

    mint ans = 0;
    rep(i, N) {
        int left = i, right = N-i;
        ans += get(left) * get(right) * a[i];
        if (i > 0) {
            ans -= get(left-1) * get(right-1) * a[i];
        }
    }
    cout << ans << endl;
    return 0;
}