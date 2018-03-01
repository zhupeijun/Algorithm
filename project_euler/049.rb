require 'prime'

def normalize(x)
  x.digits.sort.join.to_i
end


for a in 1234..9876
  for d in 1..9999
    b = a + d
    c = b + d
    next if b > 9999 || c > 9999
    k = normalize(a)
    next if normalize(b) != k
    next if normalize(c) != k
    next unless a.prime?
    next unless b.prime?
    next unless c.prime?
    puts "#{a}#{b}#{c}"
  end
end

