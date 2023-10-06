#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; ++i) cin >> A[i];
    int i = 1, j = 0;
    while (i <= N) {
        if (j+1<M&&A[j]<i) ++j;
        cout << A[j] - i << endl;
        ++i;
    }
    return 0;
}
