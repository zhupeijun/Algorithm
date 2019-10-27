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

int l[1005];
int n;

int find(int start, int x) {
    int left = start, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (l[mid] >= x) {
            right = mid - 1;
        } else if (l[mid] < x) {
            left = mid + 1;
        }
    }
    return n - right - 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &l[i]);
    }

    sort(l, l + n);

    int total = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a = l[i], b = l[j];
            int c1 = find(j + 1, b - a + 1);
            int c2 = find(j + 1, a + b);

            total += c1 - c2;
        }
    }
    printf("%d\n", total);
    return 0;
}

