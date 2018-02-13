require 'set'

s = Set.new
(1..9).to_a.permutation do |list|
  (1...7).each do |i|
    a = list[0...i].join.to_i
    (i...8).each do |j|
      b = list[i...j].join.to_i
      c = list[j..-1].join.to_i
      s << c if a * b == c
    end
  end
end

puts s.sum
