def bouncy(x)
  a = x.digits

  inc = true
  for i in 1...a.size
    if a[i] < a[i-1]
      inc = false
      break
    end
  end

  dec = true
  for i in 1...a.size
    if a[i] > a[i-1]
      dec = false
      break
    end
  end

  not inc and not dec
end


i, tot, cnt = 1, 0, 0
loop do
  tot += 1
  cnt += 1 if bouncy(i)
  if 1.0*cnt/tot >= 0.99
    puts i
    break
  end
  i += 1
end
