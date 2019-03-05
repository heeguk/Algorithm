# 정수 삼각형
num = int(input())
dp = [[0]*num for i in range(num)]
color = []
for i in range(0, num):
    color.append(list(map(int, input().split(" "))))
dp[0] = color[0]
for i in range(1, num):
    for j in range(0, i+1):
        if j == 0:
            dp[i][j] = dp[i - 1][j] + color[i][j]
        elif j == i:
            dp[i][j] = dp[i - 1][j-1] + color[i][j]
        else:
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + color[i][j]
print(max(dp[num-1]))

