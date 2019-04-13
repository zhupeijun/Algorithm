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
    int a[5];
    for (int i = 0; i < 5; ++i) {
        scanf ("%d", &a[i]);
    }

    int k;
    scanf ("%d", &k);

    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (a[j] - a[i] > k) {
                printf(":(\n");
                return 0;
            }
        }
    }
    printf ("Yay!\n");
    return 0;
}

