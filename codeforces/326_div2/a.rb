n = readline.to_i
p = 100; ans = 0; num = 0
n.times do
  a, b = readline.split().map(&:to_i)
  p = b if p > b
  ans += p * a
end
puts ans
