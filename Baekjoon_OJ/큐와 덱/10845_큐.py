from collections import deque

line = int(input())
Q = deque()

while line > 0:
    temp = input()
    op = temp.split(" ")

    if op[0] == "push":
        Q.append(op[1])
    elif op[0] == "pop":
        if len(Q) != 0:
            print(Q.popleft())
        else:
            print(-1)
    elif op[0] == "front":
        if len(Q) != 0:
            print(Q[0])
        else:
            print(-1)
    elif op[0] == "back":
        if len(Q) != 0:
            print(Q[-1])
        else:
            print(-1)
    elif op[0] == "empty":
        if len(Q) == 0:
            print(1)
        else:
            print(0)
    elif op[0] == "size":
        print(len(Q))
    line = line - 1

