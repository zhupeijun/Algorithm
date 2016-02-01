#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    ll sum = 0;
    int odd = 1000000001;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x & 1 && x < odd) odd = x;
        sum = sum + x;
    }
    if (sum & 1) sum -= odd;
    printf("%I64d\n", sum);
    return 0;
}
