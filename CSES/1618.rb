n = gets.to_i
d = 5
ans = 0
while d <= n
    ans += n / d
    d *= 5
end
puts ans