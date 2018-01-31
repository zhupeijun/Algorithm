month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

week  = 2
count = 0
for year in 1901..2000
  leap = (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)
  month.each_with_index do |d, m|
    count += 1 if week == 0
    d += 1 if leap and m == 1
    week = (week + d) % 7
  end
end

puts count
