#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve () {
    int N;
    scanf ("%d", &N);

    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        scanf ("%d", &A[i]);
    }

    for (int i = 0; i < N; ++i) {
        scanf ("%d", &B[i]);
    }

    set<int> s;

    int cut = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] < B[i]) {
            cut = -1;
            break;
        }

        while (!s.empty() && *(s.begin()) < B[i]) {
            s.erase(s.begin());
        }

        while (!s.empty() && *(s.rbegin()) > A[i]) {
            s.erase(*(s.rbegin()));
        }

        if (A[i] != B[i] && s.find (B[i]) == s.end()) {
            s.insert (B[i]);
            ++cut;
        }
    }

    printf ("%d\n", cut);
}

int main() {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; ++i) {
        solve ();
    }
    return 0;
}

