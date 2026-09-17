A = int(input())
B = int(input())
C = int(input())
D = str(A*B*C) #문자열로 바꾸어 각 자리수를 조회할수 있게 한다
E = {} #키값 0~9에 해당하는 횟수 저장 딕셔너리
for i in range(len(D)):
    E[D[i]] = E.get(D[i], 0) + 1 # D[i]는 0~9의 숫자이고 E.get(D[i], 0)은 딕셔너리 E의 키값D[i]에 대응하는 횟수 값이다, 키값이 딕셔너리에 존재하지 않을경우 D[i](키값)을 추가하고 기본값 0을 반환한다.
for i in range(10):
    print(E.get(str(i), 0)) # 0부터 차례대로 9까지 출력하고 없다면 0을 출력한다
