def to_str(x)
  a = [
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
    "hundred",
    "thousand"
  ]

  d4 = x / 1000
  x -= d4 * 1000

  d3 = x / 100
  x -= d3 * 100

  d2 = x / 10
  x -= d2 * 10

  d1 = x

  s = ""
  k = d2 * 10 + d1
  if k > 0 and k < 20
    s += a[d2 * 10 + d1 - 1]
  elsif k >= 20
    s += a[d1 - 1] if d1 > 0
    s += a[d2 + 17]
  end

  if d3 > 0
    s += a[d3 - 1]
    s += a[27]
    s += "and" if d1 > 0 or d2 > 0
  end

  if d4 > 0
    s += a[d4 - 1]
    s += a[28]
    s += "and" if d1 > 0 or d2 > 0 or d3 > 0
  end

  s
end

def main
  s = 0
  (1..1000).each { |x| s += to_str(x).length }
  puts s
end

main
