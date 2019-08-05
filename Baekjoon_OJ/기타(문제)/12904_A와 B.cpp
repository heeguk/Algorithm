#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

string S, T;

int main() {
	cin >> S >> T;
	while (1) {
		if (S == T) {
			cout << 1;
			return 0;
		}
		if (T.size() == S.size()) {
			cout << 0;
			return 0;
		}
		if (T.back() == 'A') {
			T.pop_back();
		}
		else {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}
}