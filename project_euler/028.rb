delta = 2
sum   = 1
num   = 1

while delta < 1001
  4.times { num += delta; sum += num }
  delta += 2
end

puts sum
