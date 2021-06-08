#include <iostream>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 0; i <= (n); ++i)

typedef long long ll;
typedef vector<int> vi;

int main () {
    int n; cin >> n;
    int ans = 0;
    rep(i, n) {
        int x; cin >> x;
        ans += max(0, x - 10);
    }
    cout << ans << endl;
    return 0;
}