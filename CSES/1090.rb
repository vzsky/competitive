n,x = gets.chomp.split.map(&:to_i)
w = gets.chomp.split.map(&:to_i).sort
i, j, ans = 0, w.size-1, 0
while i <= j do
  if w[i] + w[j] <= x then
    i += 1
  end
  j -= 1
  ans += 1
end
p ans