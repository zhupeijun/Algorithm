value = 1
(1..100).each { |i| value *= i }
puts value.to_s.chars.map(&:to_i).inject(:+)
