#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
int sum[100001];

int main() {
	scanf("%d %d", &N, &M);
	sum[0] = 0;
	for (int i = 1; i <= N; i++) {
		int n;
		scanf("%d", &n);
		sum[i] = sum[i - 1] + n;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int ans = sum[b] - sum[a - 1];
		printf("%d\n", ans);
	}
}