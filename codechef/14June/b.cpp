#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
  if(b == 0) return a;
  else return gcd( b, a % b);
}

int main() {
  int cn, ci;

  cin >> cn;
  for(ci = 0; ci < cn; ci++) {
    LL N, M, n, m;
    cin >> N >> M;
    n = N / 2;
    m = M / 2;

    LL a = n * (M - m) + (N - n) * m;
    LL b = N * M;

    LL g = gcd(a , b);

    cout << a / g << "/" << b / g << endl;
  } 
  return 0;
}
