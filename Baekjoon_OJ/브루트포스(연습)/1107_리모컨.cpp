#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool channel[10];

int ok(int num) {
	if (num == 0) {
		if (channel[0])
			return 1;
		else
			return 0;
	}
	int result = 0;
	while (num > 0) {
		if (!channel[num % 10])	return 0;
		num /= 10;
		result++;
	}
	return result;
}

int main() {
	memset(channel, 1, sizeof(channel));
	int target, N;
	cin >> target >> N;
	// 고장난 버튼 설정
	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;
		channel[c] = 0;
	}
	int start = 100; // 초기 채널은 100;
	int ans = abs(target - start);
	for (int i = 0; i <= 1000000; i++) {
		if (target == 100) break;
		int ch = ok(i);
		if (ch == 0) continue;
		ans = min(ans, abs(target - i) + ch);
	}
	cout << ans;

	return 0;
}