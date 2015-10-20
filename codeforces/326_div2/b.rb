n = readline.to_i
ans = 1; to = 1000005
for k in 2..to do
  if n % k == 0
    ans *= k
    while n % k == 0 do
      n /= k
    end
  end
end
puts ans * n
