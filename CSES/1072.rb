n = gets.to_i
i = 1
while i <= n
  puts ((i*i)*(i*i-1))/2 - 4*(i-1)*(i-2)
  i+=1
end