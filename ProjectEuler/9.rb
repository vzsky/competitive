for a in 1..1000 do
  for b in 1..1000 do
    c = 1000-a-b
    if c > 0 and a*a + b*b == c*c then
      p a*b*c
    end
  end
end