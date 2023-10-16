a = []
while line = gets
  a << line.chomp.split.map(&:to_i)
end

n = a.length
m = 1 << n
dp = Array.new(n+1) { Array.new(m, -1) }
dp[0][0] = 0

for i in 0...n
  for mask in 0...m
    next if dp[i][mask] < 0
    for j in 0...n
      bit = 1 << j
      if (mask & bit) == 0
        mask_new = mask | bit
        dp[i+1][mask_new] = [dp[i+1][mask_new], dp[i][mask]+a[i][j]].max
      end
    end
  end
end

p dp[n][m-1]

