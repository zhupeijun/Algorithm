require 'set'

Tn = Set.new (1..100000).to_a.map { |n| n * (n + 1) / 2 }
Pn = Set.new (1..100000).to_a.map { |n| n * (3 * n - 1) / 2 }
Hn = Set.new (1..100000).to_a.map { |n| n * (2 * n - 1) }

puts Tn.select { |x| Pn.include? x and Hn.include? x }.last
