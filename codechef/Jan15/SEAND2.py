'''
Codechef January Challenge 2015
Result: 0.638pts
This just a simple solution. Not the right answer.
'''
def swap(s, x, y):
  res = ""
  n = len(s)
  for i in range(0, n):
    if i == x:
      res = res + s[y]
    elif i == y:
      res = res + s[x]
    else:
      res = res + s[i]
  return res

def solve():
  a = raw_input()
  n = int(raw_input())
  b = map(int, raw_input().split())
  an = len(a)
  ans = -1
  minv = -1
  for i in range(0, min(an, 50)):
    t = swap(a, 0, i)
    v = int(t)
    tot = 0
    for mod in b:
      tot = tot + (v % mod)

    if i == 0:
      ans = t
    elif minv == -1 or tot < minv:
      minv = tot
      ans = t
  return ans

def main():
  t = int(raw_input())
  while t > 0:
    print solve()
    t = t - 1

main()
