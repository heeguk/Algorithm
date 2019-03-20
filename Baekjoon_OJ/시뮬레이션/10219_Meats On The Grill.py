tc = int(input())
for i in range(tc):
    h, w = map(int, input().split(" "))
    for j in range(h):
        row = input()
        print(row[::-1])