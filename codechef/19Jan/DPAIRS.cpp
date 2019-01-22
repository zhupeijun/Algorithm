#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m;
    scanf ("%d %d", &n, &m);
    vector<pii> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[i] = make_pair(x, i);
    }

    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        b[i] = make_pair(x, i);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", a[i].second, b[0].second);
    }

    for (int i = 1; i < m; ++i) {
        printf("%d %d\n", a[n - 1].second, b[i].second);
    }

    return 0;
}