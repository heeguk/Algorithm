#LCS 문제에서 문자를 추적하는게 키 포인트
# 그래프를 직접 그려보면 힌트를 얻을 수 있음

a = input()
b = input()
len_a = len(a)
len_b = len(b)

dp = [[0] * (len_a+1) for i in range(len_b+1)]

for i in range(1, len_b+1):
    for j in range(1, len_a+1):
        if b[i-1] == a[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

print(dp[len_b][len_a])
result = ""
x, y = len_b, len_a
while True:
    if b[x-1] == a[y-1]:
        result = result + b[x-1]
        x = x-1
        y = y-1
    else:
        if dp[x][y-1] >= dp[x-1][y]:
            y = y - 1
        else:
            x = x - 1
    if len(result) == dp[len_b][len_a]:
        break
print(result[::-1])
