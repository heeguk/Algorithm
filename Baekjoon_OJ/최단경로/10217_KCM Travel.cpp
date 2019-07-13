#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#define MAX 10001
using namespace std;
 
class Node
{
public:
    int next, money, time;
    Node(int a, int b,int c) { next = a, money=b, time = c; }
 
    bool operator <(const Node &n) const
    {
        return time == n.time ? money > n.money : time > n.time;
    }
};
 
int dp[111][11111];
 
int main()
{
    int testCase;
 
    cin >> testCase;
 
    for (int cases = 0; cases < testCase; cases++)
    {
        int n, m, k;
        bool visit[101] = { 0 };
        priority_queue<Node> pq;
        vector<vector <Node> > V;
 
        cin >> n >> m >> k;
        V.resize(n + 1);
 
        for (int i = 0; i < k; i++)
        {
            int u, v, x, d;
 
            cin >> u >> v >> x >> d;
 
            V[u].push_back(Node(v, x, d));
        }
 
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = 2e9;
 
        dp[1][1] = 0;
        
        pq.push(Node(1, 0, 0));
 
        while (!pq.empty())
        {
            Node temp = pq.top();
            pq.pop();
 
            int cur = temp.next, cmoney = temp.money, ctime = temp.time;
 
            if (dp[cur][cmoney] < ctime) continue;
            dp[cur][cmoney] = ctime;
 
            int len = V[cur].size();
 
            for (int i = 0; i < len; i++)
            {
                int next = V[cur][i].next, nmoney = V[cur][i].money, ntime = V[cur][i].time;
 
                if (cmoney + V[cur][i].money <= m && dp[next][cmoney+nmoney] > ctime+ntime)
                {
                    dp[next][cmoney + nmoney] = ctime + ntime;
                    pq.push(Node(next, cmoney + V[cur][i].money, dp[next][cmoney + nmoney]));
                }
            }
        }
 
        int ans = 2e9;
 
        for (int i = 1; i <= m; i++)
            if (ans > dp[n][i]) ans = dp[n][i];
 
        if (ans == 2e9) cout << "Poor KCM\n";
        else cout << ans << "\n";
 
        memset(dp, 0, sizeof(dp));
    }
}