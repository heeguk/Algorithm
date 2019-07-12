#include <iostream>
#include <cstring>
#include <vector>
#include<queue>
using namespace std;

vector <pair<int, int>> vertex[20001];
priority_queue <pair<int, int>> pq;
int dp[20001];
int check[20001];

void dik(int start) {
	
	dp[start] = 0;
	pq.push(make_pair(dp[start], start));
	
	while (!pq.empty()) {

		int node = pq.top().second;

		pq.pop();

		for (int i = 0; i < vertex[node].size(); i++) {
			int next = vertex[node][i].second;
			int weight = vertex[node][i].first;
			if (dp[next] > dp[node] + weight) {
				dp[next] = dp[node] + weight;
				pq.push(make_pair(-dp[next], next));
			}
		}
		
		check[node] = 1;

	}
	
}

int main() {

	
	memset(check, -1, sizeof(check));

	int v, e, start;
	cin >> v >> e;
	cin >> start;
	
	int v1, v2, w;
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2 >> w;
		vertex[v1].push_back(make_pair(w, v2));
	}

	for (int i = 1; i <= v; i++) {
		dp[i] = 99999999;
	}

	dik(start);

	for (int i = 1; i <= v; i++) {
		if (dp[i] == 99999999) {
			printf("%s\n", "INF");
		}
		else
			printf("%d\n", dp[i]);
	}
}