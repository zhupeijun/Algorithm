def number_of_divisor(x)
  to = Math.sqrt(x).floor
  tot = 1
  for k in 2..to
    if x % k == 0
      cnt = 1
      while x % k == 0 do
        x /= k; cnt += 1
      end
      tot *= cnt
    end
  end
  return x == 1 ? tot : tot * 2
end
def solve
  cur = 1; tot = 0
  loop do
    tot += cur
    divs_count = number_of_divisor(tot)
    return tot if divs_count >= 500
    cur += 1
  end
  return -1
end
puts solve
