tc = int(input())
cup = [0, 1, 0, 0]
for i in range(tc):
    a, b = map(int, input().split(" "))
    a, b = min(a, b), max(a, b)
    if a == 1 and b == 2:
        cup[1], cup[2] = cup[2], cup[1]
    elif a == 1 and b == 3:
        cup[1], cup[3] = cup[3], cup[1]
    elif a == 2 and b == 3:
        cup[2], cup[3] = cup[3], cup[2]
for i in range(1, 4):
    if cup[i] == 1:
        print(i)
