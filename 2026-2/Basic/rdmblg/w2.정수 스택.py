x = int(input(""))
x = [input() for i in range(x)]

class Stack:
    def __init__(self):
        self.item = []

    def push(self, item):
        self.item.append(item)

    def pop(self):
        if len(self.item) == 0:
            return -1
        return self.item.pop()

    def top(self):
        if len(self.item) == 0:
            return -1
        return self.item[-1]

    def empty(self):
        if len(self.item) == 0:
            return 1
        return 0

    def size(self):
        return len(self.item)

s = Stack()

for i in x:
    t = i.split()
    
    if t[0] == "push":
        push = int(t[1])
        s.push(push)
    elif t[0] == "pop":
        print(s.pop())
    elif t[0] == "size":
        print(s.size())
    elif t[0] == "top":
        print(s.top())
    elif t[0] == "empty":
        print(s.empty())
