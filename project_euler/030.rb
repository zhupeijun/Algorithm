puts (2..1000000).select { |x| x.digits.map { |a| a**5 }.sum == x }.sum
