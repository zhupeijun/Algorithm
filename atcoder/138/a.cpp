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


char s[20];

int main() {
    int a;
    scanf("%d", &a);
    scanf("%s", s);

    if (a >= 3200) {
        printf("%s\n", s);
    } else {
        printf("red\n");
    }
    return 0;
}

