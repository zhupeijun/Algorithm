class String
  def palindromic?
    self == self.reverse
  end
end

puts (1..999999).select { |x| x.to_s.palindromic? && x.to_s(2).palindromic? }.sum
