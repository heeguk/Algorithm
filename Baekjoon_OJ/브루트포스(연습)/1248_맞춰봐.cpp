#include <iostream>
#include <vector>

using namespace std;

int N;
char arr[10][10];
vector<int> num;

bool ok(int index){
	for (int i = 0; i < index; i++) {
		int sum = 0;
		for (int j = i; j <= index; j++) {
			sum += num[j];
		}
		if (arr[i][index] == '+' && sum <= 0)
			return false;
		if (arr[i][index] == '-' && sum >= 0)
			return false;
		if (arr[i][index] == '0' && sum != 0)
			return false;
	}
	return true;
}

void solve(int index) {
	if (index == N) {
		for (int i = 0; i < N; i++) {
			cout << num[i] << " ";
		}
		exit(0);
	}

	if (arr[index][index] == '0') {
		num.push_back(0);
		solve(index + 1);
		num.pop_back();
	}
	else if (arr[index][index] == '+') {
		for (int i = 1; i <= 10; i++) {
			num.push_back(i);
			if (ok(index))
				solve(index + 1);
			num.pop_back();
		}
	}
	else if (arr[index][index] == '-') {
		for (int i = -10; i < 0; i++) {
			num.push_back(i);
			if (ok(index))
				solve(index + 1);
			num.pop_back();
		}
	}
}

int main() {
	cin>>N;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	solve(0);
}