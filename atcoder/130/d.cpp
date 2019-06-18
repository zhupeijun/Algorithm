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

int main() {
    ll N, K;
    scanf("%lld %lld", &N, &K);
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &a[i]);
    }
    int start = 0, end = 0;
    ll sum = 0;
    ll total = 0;
    while (end < N || sum >= K) {
        if (sum >= K) {
            total += N - end + 1;
            sum -= a[start];
            ++start;
        } else {
            sum += a[end];
            ++end;
        }
    }
    printf("%lld\n", total);
    return 0;
}

