#include <iostream>
#include <algorithm>
using namespace std;

bool prime[1000001];

// 복잡하지만 에라토스테네스의 체를 이용할 수 있음.

int main() {
	prime[1] = true;
	for (int i = 2; i < 1000001; i++) {
		if (prime[i])
			continue;
		for (int j = i * 2; j < 1000001; j+=i) { // 이 부분에서 j = i * i로 하면 오버플로우가 생겨서 오류
			prime[j] = true;
		}
	}
	
	
	while (1) {
		int n;
		scanf("%d", &n);
		prime[1] = true;
		if (n == 0)
			break;

		int a, b;
		bool find = false;
		for (int i = 2; i < n; i++) {
			if (!prime[i]){ // i가 소수인 경우
				if (!prime[n - i]) {	// n-i가 소수인 경우
					find = true;
					b = n - i;
					a = i;
					break;
				}
			}
		}
		if (find) {
			printf("%d = %d + %d\n",n, a, b);
		}
		else { // 이런 경우는 존재하지 않는다.
			printf("Goldbach's conjecture is wrong.\n");
		}

	}
}