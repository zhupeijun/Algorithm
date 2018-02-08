$list = [1, 2, 5, 10, 20, 50, 100, 200]
def dfs(k, total)
  return 1 if total == 0
  return 0 if k >= $list.length || total < 0
  n = 200 / $list[k]
  (0..n).map { |i| dfs(k + 1, total - i * $list[k]) }.sum
end
puts dfs(0, 200)
