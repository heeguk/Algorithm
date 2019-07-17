#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

bool check[1001];
vector<int> vertex[1001];
int N, M, V;

void dfs(int v) {
	check[v] = 1;
	cout << v << ' ';
	for (int i = 0; i < vertex[v].size(); i++) {
		if (check[vertex[v][i]])	continue;
		dfs(vertex[v][i]);
	}
}

void bfs(int v) {
	check[v] = true;
	queue<int> q;
	q.push(v);

	while (!q.empty()) {
		int start = q.front();
		cout << start << ' ';
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
	cin >> N >> M >> V;

	int from, to;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		vertex[from].push_back(to);
		vertex[to].push_back(from);
	}
	
	for (int i = 1; i <= N; i++) {
		sort(vertex[i].begin(), vertex[i].end());
	}

	memset(check, 0, sizeof(check));
	dfs(V);
	cout << '\n';

	memset(check, 0, sizeof(check));
	bfs(V);
}