def score(name)
  name.chars.map {|c| c.ord - "A".ord + 1}.sum
end

names = File.read("p022_names.txt").gsub('"', '').split(",").sort
puts names.each_with_index.map { |name, i| score(name) * (i + 1) }.sum
