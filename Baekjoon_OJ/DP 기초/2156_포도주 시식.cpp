tc = int(input())
wine = [0]
dp = [0]*(tc+1)
for i in range(0, tc):
    wine.append(int(input()))

for i in range(1, tc+1):
    if i == 1:
        dp[1] = wine[1]
    elif i == 2:
        dp[2] = wine[2] + dp[1]
    else:
        dp[i] = max(wine[i] + wine[i-1] + dp[i-3], dp[i-1], wine[i] + dp[i-2])
# print(dp)
print(max(dp))