#include <iostream>

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++) {
		int M, N, x, y;
		scanf("%d %d %d %d", &M, &N, &x, &y);
		int find = 0;
		if (M == N) {
			if(x != y)	printf("-1\n");
			continue;
		}
		for (int i = x; i <= M * N; i += M) {
			int y_temp = (i - 1) % N;
			if (y_temp == y - 1) {
				find = 1;
				printf("%d\n", i);
				break;
			}
		}
		if (find == 0)	printf("-1\n");
	}
}