def gen
  File.open('xor.in', 'w+') do |f|
    n = 50
    f.write("#{n}\n")
    for i in 1..50
      a = rand(1..45)
      b = rand(1..45)
      a, b = b, a if a > b
      f.write("#{a} #{b}\n")
    end
  end
end

gen
