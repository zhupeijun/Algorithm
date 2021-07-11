#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define rrep(i, n) for (int i=(n-1); i>=0; --i)
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

const int M = 105;

const double EPS = 1e-6;

bool eq(double x, double y) {
    return abs(x - y) < EPS;
}

struct P {
    double x, y;

    P() { x = 0; y = 0; }

    P(double x, double y) : x(x), y(y) { }

    bool operator < (const P& o) const  {
        if (eq(x, o.x)) return y < o.y;
        else return x < o.x;
    }
};


double dist(const P& a, const P& b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(1.0*dx*dx + 1.0*dy*dy);
}

double angle(const P& a, const P& b) {
    return atan2(a.y, a.x) - atan2(b.y, b.x);
}

void rotate(P& p, double a) {
    double x = p.x * cos(a) - p.y * sin(a);
    double y = p.y * cos(a) + p.x * sin(a);
    p.x = x; p.y = y;
}

int main() {
    int N; cin >> N;
    vc<P> S(N), T(N);
    rep(i, N) cin >> S[i].x >> S[i].y;
    rep(i, N) cin >> T[i].x >> T[i].y;

    sort(rng(S));
    rrep(i, N) { S[i].x -= S[0].x; S[i].y -= S[0].y; }

    rep(i, N) { // ti -> s0
        rep(j, N) { // tj 
            rep(k, N) { // sk <-> tj
                // check dist(sk, s0) = dist(tj, ti)
                if (eq(dist(S[k], S[0]), dist(T[i], T[j]))) {
                    vc<P> R(N);
                    //copy
                    rep(l, N) R[l] = T[l];

                    // move
                    rep(l, N) { R[l].x -= T[i].x; R[l].y -= T[i].y; } 
                    double a = angle(S[k], R[j]);
                    // rotate
                    rep(l, N) rotate(R[l], a);
                    sort(rng(R));
                    bool ok = true;
                    rep(l, N) if (!eq(dist(R[l], S[l]), 0)) {
                        ok = false; break;
                    }

                    if (ok) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    } 
    cout << "No" << endl;
    return 0;
}