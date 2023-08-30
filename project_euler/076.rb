$memo = {}

def dfs(start, sum)
  key = [start, sum]
  return 0 if start > sum
  return $memo[key] if $memo.include?(key)
  ans = 1
  for v in start..sum
    ans += dfs(v, sum-v)
  end
  $memo[key] = ans
end

M = 100
ans = 0
for v in 1..M
  ans += dfs(v, M-v)
end

puts ans

