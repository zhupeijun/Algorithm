ans = 1
def gcd(a, b)
  return b == 0 ? a : gcd(b, a % b)
end
for i in 1...20
  ans *= i / gcd(ans, i)
end
puts ans

