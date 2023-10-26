n = 1<<30
ans = 0

for i in 1..n
  a, b, c = i, i*2, i*3
  ans += 1 if (a^b^c) == 0
end

puts ans
