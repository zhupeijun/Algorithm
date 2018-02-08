require 'set'
s = Set.new
(2..100).each do |a|
  (2..100).each do |b|
    s << a ** b
  end
end
puts s.length
