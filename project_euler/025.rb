f1 = 1; f2 = 1; k = 2
while f2.to_s.size < 1000
  tmp = f1 + f2
  f1 = f2
  f2 = tmp
  k += 1
end
puts k
