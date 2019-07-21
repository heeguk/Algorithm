#include <iostream>

using namespace std;

int main() {
	int start = 1;
	int end = 10;
	int target;
	cin >> target;
	int digit = 1;
	// 답이 int의 범위를 벗어나지 않는다.
	int result = 0;
	while (1) {
		if (end > target) {
			int range = target - start + 1;
			result += digit * range;
			break;
		}
		else {
			int range = end - start;
			result += digit * range;
		}
		digit++;
		start *= 10;
		end *= 10;
	}
	cout << result;
}