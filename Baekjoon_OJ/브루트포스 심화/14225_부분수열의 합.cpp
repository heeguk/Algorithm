/*
쉬운 문제!
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

int N, M;
int result = 0;
bool make[2000001];
vector<int> arr;

void solve(int n, int sum) {
	if (n == N) {
		make[sum] = true;
		return;
	}

	solve(n + 1, sum + arr[n]);
	solve(n + 1, sum);
}

int main() {
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	memset(make, 0, sizeof(make));
	solve(0, 0);

	int index = 1;
	while (1) {
		if (!make[index]) {
			cout << index << '\n';
			break;
		}
		index++;
	}
}