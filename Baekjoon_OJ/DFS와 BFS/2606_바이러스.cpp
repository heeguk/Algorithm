#include <iostream>
#include <vector>
using namespace std;

vector<int> connect[101];
int virus[101] = {0};

void dfs(int com) {
	// already infected
	if (virus[com] == 1)
		return;

	virus[com] = 1;

	for (int i = 0; i < connect[com].size(); i++) {
		dfs(connect[com][i]);
	}

}

int main() {
	int computer;
	int edge;
	cin >> computer;
	cin >> edge;
	
	for (int i = 0; i < edge; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		connect[n1].push_back(n2);
		connect[n2].push_back(n1);
	}

	dfs(1);

	int result = 0;
	for (int i = 1; i <= computer; i++) {
		if (virus[i] == 1)
			result++;
	}
	printf("%d\n", result - 1);
}