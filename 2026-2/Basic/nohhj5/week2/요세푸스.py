N, K = map(int, input().split())

i = 0
list1 = []
list2 = []
for k in range(N):
    list1.append(k+1)

while len(list1) != 0:
    i = (i + K-1) % len(list1)
    list2.append(list1.pop(i))

print('<', end="")
print(','.join(map(str, list2)))
print('>')
