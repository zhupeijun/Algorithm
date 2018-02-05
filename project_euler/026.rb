def frac(x)
  r = 1
  m = {}
  a = ""
  while not m.include? r
    m[r] = a.length
    r *= 10
    a += (r / x).to_s
    r %= x
  end
  a[m[r]...a.length]
end

max = 0
num = 0
(1...1000).each do |x|
  len = frac(x).length
  if max < len
    max = len
    num = x
    t = frac(x)
  end
end
puts num
