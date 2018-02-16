def digits_fac_sum (x)
  x.digits.map { |d| (1..d).inject(1, :*) }.sum
end

puts (10..9999999).select { |x| x == digits_fac_sum(x) }.sum


