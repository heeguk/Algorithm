tc = int(input())
for i in range(tc):
    n, m = map(int, input().split(" "))  # n/m
    while True:
        if (m/n) % 1 == 0:
            k = m/n
        else:
            k = int(m/n) + 1
        m, n = (k*m), (n*k-m)
        if n == 0:
            print(int(k))
            break

