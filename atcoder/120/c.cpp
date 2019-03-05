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

char s[100005];

int main() {
    scanf("%s", s);
    int len = strlen(s);
    int num0 = 0, num1 = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '0') {
            ++num0;
        }
    }
    num1 = len - num0;
    printf("%d\n", min(num0, num1) * 2);
    return 0;
}

