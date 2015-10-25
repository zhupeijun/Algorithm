square_sum = 0; sum = 0
for i in 1..100
  square_sum += i * i
  sum += i
end
sum_square = sum * sum
puts sum_square - square_sum

