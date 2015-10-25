def is_palindrome(x)
  s = x.to_s; n = s.size; m = n / 2
  for i in 0..m
    return false if s[i] != s[n - 1 - i]
  end
  return true
end

def solve
  ans = -1
  999.downto(100).each do |i|
    999.downto(100).each do |j|
      ans = i * j if i * j > ans and is_palindrome(i * j)
    end
  end
  return ans
end
puts solve
