# number of ranctangular (1+m)*m*(1+n)*n/4
M = 2000000
t = M
for i in 1..M
  for j in 1..M
    v = (i*(i+1)*j*(j+1))/4
    a = (v - M).abs
    if a < t
      ans = i*j
      t = a
    end
    break if v > M
  end
end

puts ans
