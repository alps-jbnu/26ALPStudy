number = input() #숫자를 문자열으로 입력받는다
len_num = len(number) #숫자의 자릿수 새기
count_six_nine = 0
A = {}
for i in range(len_num):
    if number[i] in ("6", "9"):
        count_six_nine += 1
    else:
        A[number[i]] = A.get(number[i], 0) + 1
best = max(A.values(), default=0)
print(max(best, (count_six_nine + 1) // 2))
