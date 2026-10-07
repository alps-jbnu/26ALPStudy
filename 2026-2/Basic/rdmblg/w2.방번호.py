x = input("")
listt = []

for i in range(len(x)):
  listt.append(x[i])

c = [listt.count(f'{i}') for i in range(0, 10) if i != 6 and i != 9]

sixnine = (listt.count('6')+ listt.count('9')+1)//2

a = max(max(c), sixnine)

print(a)