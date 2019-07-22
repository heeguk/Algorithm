#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char op[9];
vector<int> min_num;
vector<int> max_num;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> op[i];
	}

	for (int i = 0; i < N + 1; i++) {
		min_num.push_back(i);
		max_num.push_back(9 - i);
	}

	do {
		int find = 1;
		for (int i = 0; i < N; i++) {
			if (op[i] == '>' && min_num[i] <= min_num[i + 1]) {
				find = 0;
			}
			else if (op[i] == '<' && min_num[i] >= min_num[i + 1]) {
				find = 0;
			}
			if (find == 0)
				break;
		}
		// 정답을 찾는 순간 종료, 정답이 최소 하나는 존재한다는 문제 조건 존재.
		if (find)
			break;
	} while (next_permutation(min_num.begin(), min_num.end()));
	
	do {
		int find = 1;
		for (int i = 0; i < N; i++) {
			if (op[i] == '>' && max_num[i] <= max_num[i + 1]) {
				find = 0;
			}
			else if (op[i] == '<' && max_num[i] >= max_num[i + 1]) {
				find = 0;
			}
			if (find == 0)
				break;
		}
		// 정답을 찾는 순간 종료, 정답이 최소 하나는 존재한다는 문제 조건 존재.
		if (find)
			break;
	} while (prev_permutation(max_num.begin(), max_num.end()));

	for (int i = 0; i < N + 1; i++)	cout << max_num[i];
	cout << "\n";
	for (int i = 0; i < N + 1; i++)	cout << min_num[i];
}