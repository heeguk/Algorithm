def solve(x, y, end_x, end_y):
    global map_
    global dp
    if x == end_x and y == end_y:
        return 1
    if dp[x][y] == -1:
        dp[x][y] = 0
        if x - 1 >= 0 and map_[x][y] > map_[x - 1][y]:
            dp[x][y] = dp[x][y] + solve(x - 1, y, end_x, end_y)
        if x + 1 < m and map_[x][y] > map_[x + 1][y]:
            dp[x][y] = dp[x][y] + solve(x + 1, y, end_x, end_y)
        if y - 1 >= 0 and map_[x][y] > map_[x][y - 1]:
            dp[x][y] = dp[x][y] + solve(x, y - 1, end_x, end_y)
        if y + 1 < n and map_[x][y] > map_[x][y + 1]:
            dp[x][y] = dp[x][y] + solve(x, y + 1, end_x, end_y)

    return dp[x][y]


m, n = map(int, input().split(" "))
map_ = []
dp = [[-1]*n for i in range(m)]

for i in range(0, m):
    map_.append(list(map(int, input().split(" "))))

print(solve(0, 0, m-1, n-1))
