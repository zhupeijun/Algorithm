require 'set'

m = {}
for a in 1..1000
  for b in 1..1000
    t = a * a + b * b
    c = Math.sqrt(t).floor
    next if c * c != t
    p = a + b + c
    if p <= 1000
      k = [a, b, c].sort.join(",")
      m[p] = m[p] || Set.new
      m[p] << k
    end
  end
end
puts m.max_by { |k, v| v.size }.first
