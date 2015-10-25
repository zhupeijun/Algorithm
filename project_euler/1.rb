ans = 0
for x in 1...1000
  ans += x if x % 3 == 0 or x % 5 == 0
end
puts ans
