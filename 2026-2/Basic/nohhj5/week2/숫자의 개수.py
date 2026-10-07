# 1. 자연수 세 개 입력받고 세 수의 곱 구하기
A = int(input())
B = int(input())
C = int(input())

N = str(A*B*C)

# 2. 세 수의 등장횟수 딕셔너리에 기록하기
dictN = {}

for n in N:
    if n in dictN:
        dictN[n] += 1
    else:
        dictN[n] = 1

for i in "0123456789":
    if i not in dictN:
        dictN[i] = 0

dictN = dict(sorted(dictN.items()))

# 3. 결과 출력하기
for v in dictN.values():
    print(v)
