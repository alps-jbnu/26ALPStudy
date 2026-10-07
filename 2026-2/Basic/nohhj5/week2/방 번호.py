N = input()
numDict = {}

for n in N:
    if n not in numDict:
        numDict[n] = 1
    else:
        numDict[n] += 1

for i in '0123456789':
    if i not in numDict:
        numDict[i] = 0
sum6n9 = (numDict['6'] + numDict['9'])

if sum6n9 % 2 == 0:
    numDict['6'] = sum6n9 // 2
else:
    numDict['6'] = sum6n9 // 2 + 1
numDict['9'] = 0

maxVal = max(numDict.values())
print(maxVal)
