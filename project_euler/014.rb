maxv = 1; maxn = 1
MAXN = 1000000
m = [0] * (MAXN + 1)
(1..MAXN).each do |i|
  x = i; len = 1
  while x != 1
    if x < i
      len += m[x]
      break
    else
      if x % 2 == 0
        x /= 2
      else
        x = 3 * x + 1
      end
      len += 1
    end
  end
  m[i] = len - 1
  if len > maxn
    maxn = len
    maxv = i
  end
end

puts maxv

