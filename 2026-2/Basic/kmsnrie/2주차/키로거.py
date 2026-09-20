T = int(input())

for _ in range(T):
    s = input().strip()
    left = []
    right = []

    for char in s:
        if char == '<':
            if left:
                right.append(left.pop())
        elif char == '>':
            if right:
                left.append(right.pop())
        elif char == '-':
            if left:
                left.pop()
        else:
            left.append(char)

    print(''.join(left) + ''.join(reversed(right)))
