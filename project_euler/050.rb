require 'prime'

N = 1000000
list = Prime.each(N).to_a
n = list.size
r = {}
for i in 0...n
  sum = 0
  for j in i...n
    sum += list[j]
    break if sum > N
    count = j - i + 1
    r[sum] = count if sum.prime? and count > (r[sum] || 0)
  end
end

puts r.max_by { |k, v| v }.first
