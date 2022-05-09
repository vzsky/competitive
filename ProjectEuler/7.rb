primes = (0..150000).to_a
primes[0] = primes[1] = nil

for i in 2..150000 do
  for j in 2..(150000/i) do
    primes[i*j] = nil
  end
end

p (primes.compact)[10000]
