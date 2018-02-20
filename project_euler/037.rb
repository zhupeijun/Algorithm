require 'prime'

def ok?(s)
  s.size.times.collect { |k| s[0..k].to_i.prime? && s[k..-1].to_i.prime? }.inject(:&)
end

puts (10..999999).select { |x| ok?(x.to_s) }.sum
