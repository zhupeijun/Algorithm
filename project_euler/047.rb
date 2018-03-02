require 'prime'
require 'set'

N = 200000

@list = Prime.each(N).to_a
def ok? x
  count = 0
  @list.each do |t|
    count += 1 if x % t == 0
    while x % t == 0
      x /= t
    end
    break if x == 1
  end
  count == 4
end

nums = (1..N).to_a.select {|x| ok? x }
puts nums.slice_when {|p, c| p.next != c }.select {|a|a.size > 3}.first.first

