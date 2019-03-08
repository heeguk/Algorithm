# 계단 오르기
# 점화식을 잘 생각하기, 특이한 점화식
# 내가 처음에 풀었던 방식은 효율적이지 않음
# 계단을 밟을 수 있는 경우를 따져보기
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

