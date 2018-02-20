require 'prime'

count = 0
for x in 1..999999
  d = x.digits
  n = d.length
  count += 1 if (0...n).map { |k| d.rotate(k).join.to_i.prime? }.inject(:&)
end

puts count
