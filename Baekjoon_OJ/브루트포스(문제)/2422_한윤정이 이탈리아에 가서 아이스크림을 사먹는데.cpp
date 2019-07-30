#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
bool combination[201][201];

int main() {
	cin >> N >> M;
	memset(combination, 0, sizeof(combination));
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		combination[a][b] = 1;
		combination[b][a] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)	continue;
			for (int k = 1; k <= N; k++) {
				if (i == k || j == k)	continue;
				if (combination[i][j] || combination[j][k] || combination[i][k])	continue;
				ans++;
			}
		}
	}
	cout << ans / 6;
}