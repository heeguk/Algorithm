# 인원이 홀수인 경우만 잘 생각해주기
n, a, b = map(int, input().split(" "))
a, b = min(a, b) - 1, max(a, b) - 1
turn = 0
while True:
    turn = turn + 1
    end = False
    for i in range(0, int(n/2)):
        if a == 2*i and b == 2*i + 1:
            end = True
            break
        if a == 2*i or a == 2*i + 1:
            a = i
        if b == 2*i or b == 2*i + 1:
            b = i
            break
    if n % 2 == 1:
        if b == n - 1:
            b = int(n / 2)
        n = int(n/2) + 1
    else:
        n = int(n/2)
    if end:
        break
print(turn)
