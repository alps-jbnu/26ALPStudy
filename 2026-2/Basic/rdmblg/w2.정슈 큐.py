x = int(input(""))
listt = []

for i in range(x):
  y = input()
  if y[0:2] == 'pu':
    y = y.replace("push ", "")
    listt.append(y)
  elif y[0:2] == 'po':
    if listt == []:
      print(-1)
    else :
      x = listt.pop(0)
      print(x)
  elif y[0] == 's':
    print(len(listt))
  elif y[0] == 'e':
    if listt == [] :
      print(1)
    else :
      print(0)
  elif y[0] == "f":
    if listt == []:
      print(-1)
    else :
      print(listt[0])
  elif y[0] == "b":
    if listt == [] :
      print(-1)
    else :
      print(listt[len(listt)-1])
