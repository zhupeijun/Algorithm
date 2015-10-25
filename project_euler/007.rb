MAX = 500005
is_prime = [true] * MAX
is_prime[0] = is_prime[1] = false
for i in 2...MAX
  if is_prime[i] == true
    j = 2
    while i * j < MAX
      is_prime[i * j] = false
      j += 1
    end
  end
end
cnt = 0; ans = -1
for i in 2...MAX
  cnt += 1 if is_prime[i] == true
  if cnt == 10001
    ans = i
    break
  end
end
puts ans

