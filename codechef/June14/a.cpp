#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

int main() {
  int n, a, i, len = 0, ans = 0;

  scanf("%d", &n);
  for(i = 0;i < n; i++) {
    scanf("%d", &a);
    if(a == 0) len = 0;
    else len = len + 1;
    ans = max(ans, len);
  }
  printf("%d\n", ans);
  return 0;
}
