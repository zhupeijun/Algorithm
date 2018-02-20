def product(a, n)
  (1..n).map { |i| a * i }.join
end

max_value = 0
for x in 1..99999
  n = 2
  loop do
    p = product(x, n)
    break if p.size > 9
    max_value = [p.to_i, max_value].max if p.chars.sort.join == "123456789"
    n += 1
  end
end

puts max_value
