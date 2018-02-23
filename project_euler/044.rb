# This code just find the first candidate. But still not clear about why the
# first candidate is the minimised

require 'set'
a = (1..5000).to_a.map {|x| x * (3 * x - 1) / 2}
s = Set.new a
n = a.size
r = []
for i in 0...n
  for j in i...n
    x = a[i]
    y = a[j]

    sum  = x + y
    break if sum > a.last

    diff = (x - y).abs

    r << diff if s.include?(sum) and s.include?(diff)
  end
end
puts r.first

