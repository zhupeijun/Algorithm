a1 = 1; a2 = 2
ans = 0
while a2 < 4000000
  ans += a2 if a2 % 2 == 0
  t = a2; a2 = a1 + a2; a1 = t
end
puts ans
