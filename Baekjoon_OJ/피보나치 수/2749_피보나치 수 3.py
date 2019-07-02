num = int(input())

p = 100000 * 15
F = [0] * (p+1)
F[0] = 0
F[1] = 1
for i in range(2, num % p + 1):
    F[i] = (F[i-2] + F[i-1]) % 1000000

print(F[num % p])
