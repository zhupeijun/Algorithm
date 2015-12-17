def solve
  a = readline.to_i(7)
  b = readline.to_i(7)
  l = readline.to_i

  c = a / b
  ans = c % (7**l)
  puts ans.to_s(7)
end

def main
  t = readline.to_i
  while t > 0
    solve
    t -= 1
  end
end

main
