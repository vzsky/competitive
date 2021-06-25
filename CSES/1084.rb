n,m,k = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i).sort
b = gets.chomp.split.map(&:to_i).sort
i, j, ans = 0, 0, 0
while i < a.size and j < b.size do
  if b[j]-k <= a[i] and a[i] <= b[j]+k then
    ans += 1
    i += 1
    j += 1
  elsif b[j]-k > a[i] then i += 1
  else j += 1
  end
end
p ans