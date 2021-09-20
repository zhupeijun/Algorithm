#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define each(v, i) for (auto i : v) 
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define maxs(x, y) x = max(x, y)
#define mins(x, y) x = min(x, y)
#define pcnt __builtin_popcount
#define rng(a) a.begin(), a.end()

template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
using vi = vc<int>;


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

using mt = modint<1000000007>;

void solve() {
    int N; cin>>N;
    string S; cin>>S;

    mt len = 0;
    rep(i, N) {
        if (S[i] != '.') len+=1;
        else len*=2;
    }

    mt first = 0, last = 0;
    mt m = 0, ans = 0, cnt = 0, mid = 0, L = 0, R = 0;
    char fc = 0, lc = 0;
    rep(i, N) {
        char c = S[i];
        if (c == 'F') {
            last += 1;
            m += 1;
        } else if (c == 'O' || c == 'X') {
            if (fc == 0) {
                first = m;
                fc = c;
            } else if (lc != c) {
                mt r = len-m;
                mt l = m-last;
                ans += l*r;
                cnt += 1;
                mid += r-l; L+=l; R+=r;
            }
            m+=1;
            lc = c; last = 0;
        } else {
            ans += ans;
            ans += m*(R-L);
            ans -= cnt*m*m;

            L = L*2+cnt*m;
            R = R*2-cnt*m;
            mid = mid*2-m*2*cnt;
            cnt *=2;
            if (lc != fc) {
                mt l = m-last;
                mt r = len-(m+first);
                ans += l*r;
                cnt += 1;
                mid += r-l; L+=l; R+=r;
            }
            m*=2;
        }
    }
    cout << ans << endl;
}

int main() {
    int T; cin>>T;
    rep(i, T) {
        cout << "Case #"<<(i+1)<<": ";
        solve();
    }
    return 0;
}