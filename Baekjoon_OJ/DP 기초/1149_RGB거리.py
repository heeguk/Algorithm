# RGB 컬러
num = int(input())
dp = [[0]*3 for i in range(num+1)]
color = []
for i in range(0, num):
    color.append(list(map(int, input().split(" "))))
    dp[i + 1][0] = color[i][0] + min(dp[i][1], dp[i][2])
    dp[i + 1][1] = color[i][1] + min(dp[i][0], dp[i][2])
    dp[i + 1][2] = color[i][2] + min(dp[i][0], dp[i][1])
print(min(dp[num]))
