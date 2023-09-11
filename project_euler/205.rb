def dfs(k, n, m, s, d)
  if k == n
    d[s] += 1
    return
  end

  for i in 1..m
    dfs(k+1, n, m, s+i, d)
  end
end


d4 = Hash.new(0)
d6 = Hash.new(0)

dfs(0, 9, 4, 0, d4)
dfs(0, 6, 6, 0, d6)


s4 = d4.values.sum
s6 = d6.values.sum

ans = 0
for k4, v4 in d4
  for k6, v6 in d6
    if k4 > k6
      ans += 1.0*v4/s4 * 1.0*v6/s6
    end
  end
end

puts sprintf("%.7f", ans)
