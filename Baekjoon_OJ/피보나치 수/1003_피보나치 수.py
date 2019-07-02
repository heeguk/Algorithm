tc = int(input())
for i in range(0, tc):
    num = int(input())
    f = []*(num + 1)
    f.append((1, 0))
    f.append((0, 1))
    for n in range(2, num+1):
        a = f[n-1]
        b = f[n-2]
        f.append((f[n-1][0]+f[n-2][0], f[n-1][1]+f[n-2][1]))
    print(f[num][0], f[num][1])

