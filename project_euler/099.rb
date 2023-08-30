nums = []
File.readlines('0099_base_exp.txt').each do |line|
  nums << line.split(',').map(&:to_i)
end

maxv = nil
maxi = -1
nums.each_with_index do |e, i|
  if maxi == -1
    maxv = e
    maxi = i
  else
    x = Math.log(e[0]) * e[1]
    y = Math.log(maxv[0]) * maxv[1]
    if x > y
      maxv = e
      maxi = i
    end
  end
end

puts maxi+1

