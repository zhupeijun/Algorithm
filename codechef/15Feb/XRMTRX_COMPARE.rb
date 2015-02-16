def gen(n)
  (1..n).map { |i| (1..n).map { |j|  i ^ j } }
end

def dfs(g, rs, r, c, n, m, lp, rp)
  return if r < lp or r > rp or c < lp or c > rp
  rs[r][c] = rs[r][c] + 1
  [[1, 0], [-1, 0], [0, 1], [0, -1]].each do |dx, dy|
    x = r + dx
    y = c + dy
    if x >= 0 and x < n and y >= 0 and y < m and g[x][y] - g[r][c] == 1
      dfs(g, rs, x, y, n, m, lp, rp)
    end
  end
end

def output(rs)
  rs.each do |r|
    r.each_with_index do |c, j|
      print "#{c}#{j == r.size - 1 ? "\n" : " " }"
    end
  end
end

def run(n, lp, rp)
  lp = lp - 1; rp = rp - 1
  g = gen(n)
  rs = g.map { |r| r.map { |c| 0 } }
  n = rs.size
  m = rs[0].size
  (0...n).each { |i| dfs(g, rs, i, i, n, m, lp, rp) }
  ans1 = 0
  ans2 = 0
  rs.each_with_index do |r, i|
    r.each_with_index do |c, j|
      if rs[i][j] > 0 and g[i][j] > ans1
        ans1 = g[i][j]
      end
    end
  end

  rs.each_with_index { |r, i| r.each_with_index { |c, j| ans2 = ans2 + c if ans1 == g[i][j] } }
  puts "#{ans1} #{ans2}"
end

def main
  t = gets.to_i
  while t > 0
    t = t - 1
    (i, j) = gets.split(' ').map { |a| a.to_i }
    run(50, i, j)
  end
end

main
