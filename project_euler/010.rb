N = 2000000
def solve
  is_prime = [true] * N
  is_prime[0] = is_prime[1] = false
  for i in 2...N
    if is_prime[i] == true
      for j in 2...N
        break if i * j >= N
        is_prime[i * j] = false
      end
    end
  end
  ans = 0
  for i in 0...N
    ans += i if is_prime[i]
  end
  return ans
end
puts solve
