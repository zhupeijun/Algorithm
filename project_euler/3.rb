a = 600851475143; k = 2
ans = 600851475143
while a > 1 and k < 1000000
  if a % k == 0
    while a % k == 0
      a /= k
    end
    ans = k
  end
  k += 1
end
ans = a if a != 1
puts ans
