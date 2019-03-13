/*
쉬운문제.
중복하는 경우를 없애줘야함.
없애는 방법을 잘 생각해보기.
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

int N, M;

bool combination[201][201];

int main() {
	cin >> N >> M;
	
	memset(combination, 0, sizeof(combination));

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		combination[a][b] = true;
		combination[b][a] = true;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			for (int k = 1; k <= N; k++) {
				if (i == k || j == k)
					continue;
				if (combination[i][j] || combination[i][k] || combination[j][k])
					continue;
				ans++;
			}
		}
	}
	cout << ans / 6 << '\n';
}