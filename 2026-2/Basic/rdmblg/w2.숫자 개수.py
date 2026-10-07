listt = [input() for i in range(3)]

baby = 1
for i in listt :
  baby = baby * int(i)


for i in range(0, 10, 1):
  print(str(baby).count(f"{i}"))
