#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool visit[1001];
vector<int> vertex[1001];

int n, m, v;

void dfs(int v) {
	visit[v] = true;
	cout << v << ' ';
	
	for (int i = 0; i < vertex[v].size(); i++) {
		int to = vertex[v][i];
		if (visit[to] == false) {
			dfs(to);
		}
	}
}

void bfs(int v) {
	queue<int> q;
	visit[v] = true;
	q.push(v);

	while (!q.empty()) {
		int from = q.front();
		q.pop();
		cout << from << ' ';

		for (int i = 0; i < vertex[from].size(); i++) {
			int to = vertex[from][i];
			if (visit[to] == false) {
				visit[to] = true;
				q.push(to);
			}
		}
	}
}

int main() {
	cin >> n >> m >> v;
	
	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		vertex[from].push_back(to);
		vertex[to].push_back(from);
	}

	for (int i = 1; i <= n; i++) {
		sort(vertex[i].begin(), vertex[i].end());
	}

	memset(visit, 0, sizeof(visit));
	dfs(v);
	cout << '\n';

	memset(visit, 0, sizeof(visit));
	bfs(v);
	cout << '\n';
}