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
    int A, B;
    scanf ("%d %d", &A, &B);
    int total = 1;
    int need = 0;
    while (total < B) {
        total = total - 1 + A;
        ++need;
    }
    printf("%d\n", need);
    return 0;
}

