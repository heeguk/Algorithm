#include <iostream>

using namespace std;

int N;
int B, C;
int arr[1000000];
long long ans = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> B >> C;
	

	for (int i = 0; i < N; i++) {
		ans += 1;	// 총 감독관은 항상 1명 존재
		if (B >= arr[i])	continue;
		else {
			int student = arr[i] - B;
			int sub = (student / C) + 1;
			if (student % C == 0)	sub--;
			ans += sub;
		}
	}

	cout << ans;
}