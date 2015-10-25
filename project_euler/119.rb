MAX = 10000000000000000
def solve
  k = 2; ans = []
  while k <= 144
    base = k
    while base < MAX
      if base > 9
        tot = base.to_s.chars.map(&:to_i).inject(:+)
        ans << base if tot == k
      end
      base *= k
    end
    k += 1
  end
  ans.size >= 30 ? ans.sort[29] : -1
end
puts solve
