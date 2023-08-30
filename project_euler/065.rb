M = 98

a=[2]
for i in 0..M
  if i % 3 == 0 || i % 3 == 2
    a << 1
  else
    a << (i/3+1)*2
  end
end

x = y = nil
a.reverse_each do |v|
  if x.nil?
    x, y = 1, v
  else
    t = y*v+x
    x, y = y, t
  end
end

p y.digits.sum
