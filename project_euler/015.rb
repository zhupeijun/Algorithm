dp = Array.new(21) { Array.new(21, 0) }
dp[0][0] = 1
for i in 0..20
  for j in 0..20
    dp[i][j] += dp[i - 1][j] if i > 0
    dp[i][j] += dp[i][j - 1] if j > 0
  end
end
puts dp[20][20]
