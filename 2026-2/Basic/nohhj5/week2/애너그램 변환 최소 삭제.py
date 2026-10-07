# 1. 입력받기

A = input()
B = input()

# 2. 알파벳의 개수 세기

dictA = {}
dictB = {}

for i in A:
    if i in dictA:
        dictA[str(i)] += 1
    else:
        dictA[str(i)] = 1

for j in B:
    if j in dictB:
        dictB[str(j)] += 1
    else:
        dictB[str(j)] = 1

# 3. 알파벳 개수 비교

count = 0

for k in 'abcdefghijklmnopqrstuvwxyz':
    a = dictA.get(str(k), 0)
    b = dictB.get(str(k), 0)

    if a != b:
        count += abs(a-b)

# 4. 정답 출력

print(count)
