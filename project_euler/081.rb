mat = []
File.readlines('matrix.txt').each do |line|
    r = line.split(",").map(&:to_i)
    mat << r
end

N = mat.size
M = mat[0].size

v = Array.new(N).map{Array.new(M, 0)}

for i in 0...N
    for j in 0...M
        if i == 0 and j == 0
            v[i][j] = mat[i][j]
        elsif i == 0
            v[i][j] = mat[i][j] + v[i][j-1]
        elsif j == 0
            v[i][j] = mat[i][j] + v[i-1][j]
        else
            v[i][j] = mat[i][j] + [v[i-1][j],v[i][j-1]].min
        end
    end
end

puts v[N-1][M-1]
