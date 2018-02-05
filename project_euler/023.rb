require 'set'

def is_abundant(x)
  sum = 0
  (1...x).each do |t|
    sum += t    if x % t == 0
    return true if sum > x
  end
  return false
end

abundants = (1..28123).select {|x| is_abundant(x) }

s = Set.new
abundants.each do |a|
  abundants.each do |b|
    sum = a + b
    s << sum if sum <= 28123
  end
end

puts (1..28123).select { |x| not s.include? x }.sum
