from collections import deque

line = int(input())
Q = deque()

for i in range(0, line):
    length, target = map(int, input().split(" "))
    weight = list(input().split(" "))
    find = [0] * length
    find[target] = 1

    order = 1
    while True:
        if weight[0] == max(weight):
            if find[0] == 1:
                print(order)
                break
            weight.pop(0)
            find.pop(0)
            order = order + 1
        else:
            weight.append(weight.pop(0))
            find.append(find.pop(0))