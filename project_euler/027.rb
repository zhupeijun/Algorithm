N = 2000000
is_prime = [true] * N
is_prime[0] = is_prime[1] = false
for i in 1...N
  if is_prime[i]
    for j in 2...N
      k = i * j
      break if k >= N
      is_prime[k] = false
    end
  end
end

M = 999
max_num = 0
product = 1
for a in -M..M
  for b in -M..M
    k = 0
    while is_prime[(k * k + a * k + b).abs]
      k = k + 1
    end
    if max_num < k
      max_num = k
      product = a * b
    end
  end
end
puts product


