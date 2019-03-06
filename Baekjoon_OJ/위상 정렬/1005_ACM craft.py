import sys

tc = int(sys.stdin.readline())

for i in range(0, tc):
    N, K = map(int, sys.stdin.readline().split(" "))
    B = list(map(int, sys.stdin.readline().split(" ")))
    edge = [[] for i in range(N)]
    degree = [0] * N
    for j in range(0, K):
        a, b = map(int, sys.stdin.readline().split(" "))
        degree[b-1] = degree[b-1] + 1
        edge[a-1].append(b-1)
    Q = []
    order = []
    target = int(input())
    while True:
        for j in range(0, len(degree)):
            if degree[j] == 0:
                degree[j] = -1
                Q.append(j)
        while len(Q) != 0:
            node = Q.pop(-1)
            order.append(node)
            for k in edge[node]:
                degree[k] = degree[k] - 1
        if len(order) == N:
            break
    dp = [0]*N
    dp[order[0]] = B[order[0]]

    while True:
        node = order.pop(0)
        for e in edge[node]:
            dp[e] = max(dp[e], dp[node] + B[e])
        if len(order) == 0:
            break
    print(dp[target - 1])

