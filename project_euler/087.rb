require 'prime'
require 'set'

N = 7200
M = 50000000

prime_list = Prime.take_while { |prime| prime < M }

s = Set.new
for i in prime_list
  a = i**2
  break if a >= M
  for j in prime_list
    b = a + j**3
    break if b >= M
    for k in prime_list
      c = b + k**4
      break if c >= M
      s << c
    end
  end
end

puts s.size
