#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

bool check[20001];
vector<int> vertex[20001];
int color[20001];
int V, E;

int dfs(int v, int Color) {
	check[v] = 1;
	color[v] = Color;
	//cout << v << ' ';
	for (int i = 0; i < vertex[v].size(); i++) {
		if (check[vertex[v][i]]) {
			if (color[vertex[v][i]] == Color)
				return true;
			continue;
		}
		int wrong = dfs(vertex[v][i], 3-Color);

		if (wrong)
			return true;
	}
	return false;
}

void bfs(int v) {
	check[v] = true;
	queue<int> q;
	q.push(v);

	while (!q.empty()) {
		int start = q.front();
		//cout << start << ' ';
		q.pop();

		for (int i = 0; i < vertex[start].size(); i++) {
			int to = vertex[start][i];
			if (check[to])	continue;
			check[to] = true;
			q.push(to);
		}

	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		memset(color, 0, sizeof(color));
		cin >> V >> E;
		for (int i = 0; i < E; i++) {
			int from, to;
			cin >> from >> to;
			vertex[from].push_back(to);
			vertex[to].push_back(from);
		}

		

		// 모든 정점에서 bfs 실시
		memset(check, 0, sizeof(check));
		int wrong = 0;
		for (int i = 1; i <= V; i++) {
			if (color[i] == 0)
				color[i] = 1;
			if(!check[i])
				wrong = dfs(i, color[i]);
			if (wrong)
				break;
		}
		if (wrong)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
		for (int i = 1; i < 20001; i++) vertex[i].clear();
	}
}