x = [int(input()) for i in range(5)]

y = sorted(x)

a = 0
for i in range(len(x)):
    a += y[i]

print(int(a/5))
print(y[2])
