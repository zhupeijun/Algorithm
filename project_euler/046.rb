require 'prime'

x = 1
loop do
  x += 2
  next if x.prime?
  i = 1
  ok = false
  loop do
    b = 2 * i * i
    break if b >= x
    if (x - b).prime?
      ok = true
      break
    end
    i += 1
  end
  unless ok
    puts x
    break
  end
end
