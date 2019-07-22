#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ability[20][20];
vector<int> team;
int N;

int calculate() {
	vector<int> first, second;
	for (int i = 0; i < N; i++) {
		if (team[i] == 0)
			first.push_back(i);
		else
			second.push_back(i);
	}
	int first_sum = 0;
	for (int i = 0; i < first.size(); i++) {
		for (int j = 0; j < first.size(); j++) {
			if (i == j)	continue;
			first_sum += ability[first[i]][first[j]];
		}
	}
	int second_sum = 0;
	for (int i = 0; i < second.size(); i++) {
		for (int j = 0; j < second.size(); j++) {
			if (i == j)	continue;
			second_sum += ability[second[i]][second[j]];
		}
	}

	return abs(first_sum - second_sum);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ability[i][j];
		}
		if (i < N / 2)
			team.push_back(0);
		else
			team.push_back(1);
	}

	int ans = 40000000;

	do {
		ans = min(ans, calculate());
	} while (next_permutation(team.begin(), team.end()));
	cout << ans;
}