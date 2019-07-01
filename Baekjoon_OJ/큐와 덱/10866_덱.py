line = int(input())
deque = []


for i in range(0,line):
    temp = input().split(" ")
    op = temp[0]
    if op == "push_back":
        number = int(temp[1])
        deque.append(number)
    elif op == "push_front":
        number = int(temp[1])
        deque.insert(0, number)
    elif op == "back":
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[-1])
    elif op == "front":
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[0])
    elif op == "size":
        print(len(deque))
    elif op == "empty":
        if len(deque) == 0:
            print(1)
        else:
            print(0)
    elif op == "pop_back":
        if len(deque) == 0:
            print(-1)
        else:
            print(deque.pop(-1))
    elif op == "pop_front":
        if len(deque) == 0:
            print(-1)
        else:
            print(deque.pop(0))



