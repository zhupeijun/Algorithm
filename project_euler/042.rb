
def words_value (w)
  w.chars.map { |c| c.ord - 'A'.ord + 1 }.sum
end

tri_nums = (1..20).to_a.map{ |x| x * (x + 1) / 2 }

words = File.read("p042_words.txt").gsub('"', '').split(",")
puts words.select { |w| tri_nums.include? words_value(w) }.count
