sum = 0
(1..1000).each do |x|
  sum += x**x
  sum %= 10000000000
end
puts "%010d" % sum

