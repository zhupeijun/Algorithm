require 'prime'

max_value = 0
for i in 1..9
  primes = (1..i).to_a.permutation.map { |a| a.join.to_i }.select { |x| x.prime? }
  max_value = primes.max unless primes.empty?
end
puts max_value
