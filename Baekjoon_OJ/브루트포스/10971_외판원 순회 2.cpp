#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vec;
int map[10][10];

int main() {
	
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
		vec.push_back(i);
	}

	int result = 999999999;

	do {
		int sum = 0;
		int wrong = 0;
		for (int i = 1; i < n; i++) {
			if (map[vec[i - 1]][vec[i]] == 0)
				wrong = 1;
			sum += map[vec[i - 1]][vec[i]];

		}
		if (!wrong && map[vec[n - 1]][vec[0]] != 0) {
			sum += map[vec[n - 1]][vec[0]];
			result = min(result, sum);
		}
	} while (next_permutation(vec.begin() + 1, vec.end()));

	cout << result;
}