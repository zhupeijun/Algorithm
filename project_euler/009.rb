def solve
  for b in 0..1000
    for a in 0...b
      c = 1000 - a - b
      break if a + b > 1000 or c <= b
      if a**2 + b **2 == c**2
        return a * b * c
      end
    end
  end
  return -1
end
puts solve
