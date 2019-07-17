#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

bool check[2001];
vector<int> vertex[2001];
int V, E;

int dfs(int v, int depth) {
	check[v] = 1;
	if (depth == 5)
		return true;
	for (int i = 0; i < vertex[v].size(); i++) {
		if (check[vertex[v][i]])
			continue;
		int ok = dfs(vertex[v][i], depth + 1);
		if (ok)
			return true;
	}
	check[v] = 0;
	return false;
}


int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int from, to;
		cin >> from >> to;
		vertex[from].push_back(to);
		vertex[to].push_back(from);
	}

	int ok = 0;
	for (int i = 0; i < V; i++) {
		memset(check, 0, sizeof(check));
		ok = dfs(i, 1);
		if (ok)
			break;
	}
	if (ok)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}