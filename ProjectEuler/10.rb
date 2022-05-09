primes = (0..2000000).to_a
primes[0] = primes[1] = nil

for i in 2..2000000 do
  for j in 2..(2000000/i) do
    primes[i*j] = nil
  end
end

p primes.compact.sum
