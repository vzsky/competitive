n = gets.to_i
i = 0
while i < n
  row = gets.chomp.split.map(&:to_i)
  if (row[0] + row[1]) % 3 == 0 && row[0] <= 2*row[1] && row[1] <= 2*row[0]
    puts "YES"
  else
    puts "NO"
  end
  i += 1
end