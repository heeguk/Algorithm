# 계단 오르기
num = int(input())
dp = [0]*(num+1)
stair = [0]*(num+1)
# Initialization
for i in range(1, num+1):
    stair[i] = int(input())
dp[0] = 0
dp[1] = stair[0]

# Solve
for i in range(1, num+1):
    if i - 3 >= 0:
        dp[i] = max(dp[i-3] + stair[i-1] + stair[i], dp[i-2] + stair[i])
    else:
        dp[i] = max(dp[i-1] + stair[i], dp[i-2]+stair[i])
print(dp[num])

