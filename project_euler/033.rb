x = y = 1
for a in 10..99
  for b in 10..99
    next if b <= a

    a1 = a % 10
    a2 = a / 10

    b1 = b % 10
    b2 = b / 10

    if (a1 == b2 and a2 * b == b1 * a) or (a2 == b1 and a1 * b == b2 * a)
      x *= a
      y *= b
    end
  end
end
puts y / x.gcd(y)

