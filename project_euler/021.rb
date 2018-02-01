
def d(x)
  (1...x).select { |k| x % k == 0 }.inject(:+)
end

sum = 0
for a in 2..9999
  b = d(a)
  x = d(b)
  sum += a if x == a and a != b
end

puts sum

