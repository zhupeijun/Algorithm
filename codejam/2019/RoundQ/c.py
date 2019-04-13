import sys
import math

def gcd(a, b):
  if (b == 0):
    return a
  else:
    return gcd(b, a % b)

def solve():
  n, l = map(int, raw_input().split())
  a = [0] * (l + 1)
  t = map(int, raw_input().split())
  mid = 1
  while t[mid] == t[mid - 1]:
    mid = mid + 1

  a[mid] = gcd(t[mid], t[mid - 1])
  for i in range(mid - 1, -1, -1):
    a[i] = t[i] / a[i + 1]
  for i in range(mid + 1, l + 1):
    a[i] = t[i - 1] / a[i - 1]

  k = 0
  d = {}
  p = list(set(a))
  p.sort()
  for v in p:
    d[v] = chr(ord('A') + k)
    k = k + 1

  for v in a:
    sys.stdout.write(d[v])
  print ''

def main():
  t = int(raw_input())
  for i in range(1, t + 1):
    sys.stdout.write("Case #{}: ".format(i))
    solve()

main()
