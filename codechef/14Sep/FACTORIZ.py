import sys

prime = []

def get_prime():
  n = 50001
  isprime = [True] * n
  isprime[0] = isprime[1] = False
  for i in range(2, n):
    if isprime[i]:
      j = 2
      while i * j < n:
        isprime[i * j] = False
        j = j + 1
      prime.append(i)

def sep(x):
  ans = []
  if x == 1:
    ans.append(1)
    return ans
  k = 0
  for p in prime:
    if x > 1 and x % p == 0:
      while x % p == 0:
        x /= p
        ans.append(p)
        k = k + 1
  if x != 1:
    ans.append(x)
  return ans

def main():
  sin = sys.stdin
  sout = sys.stdout
  get_prime()
  t = int(sin.readline())

  while t > 0:
    n = int(sin.readline())
    ans = sep(n)
    sout.write("%s\n" % len(ans))
    for a in ans:
      sout.write("%s\n" % a)
    t = t - 1

main()

