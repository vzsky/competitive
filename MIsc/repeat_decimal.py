d = int(input('find 1/x, type x: '))
print(f"calculating 1/{d}")

ans = [0]
xs = []
x = 1

while True:
  x *= 10
  res = x // d
  rem = x % d

  if x in xs :
    xs.append(x)
    break

  ans.append(res)
  xs.append(x)

  if rem == 0 : break
  x = rem

start = -1
for i in range(len(xs)-1) :
  if xs[-1] == xs[i] : 
    start = i+1

repeat = ''.join([str(x) for x in ans[start:]]) if start != -1 else '0';
ans = [str(x) for x in ans]
print("0."+''.join(ans[1:])+repeat)

