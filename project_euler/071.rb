M = 1000000

x = y = nil
for i in 1..M
  a = i*3/7
  a -= 1 while a.gcd(i) != 1
  next if a <= 0 || (a==3 and i == 7)
  if x.nil? or a*y > x*i
    x, y = a, i
  end
end

puts x
