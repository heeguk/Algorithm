#include <iostream>

using namespace std;

int arr[100];

int C, P;

void solve(int type) {
	int ans = 0;
	if (type == 1) {
		for (int i = 0; i < C; i++) {
			ans++;
		}
		for (int i = 0; i + 3 < C; i++) {
			if (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2] && arr[i + 2] == arr[i + 3])	ans++;
		}
	}
	else if (type == 2) {
		for (int i = 0; i + 1 < C; i++) {
			if (arr[i] == arr[i + 1])	ans++;
		}
	}
	else if (type == 3) {
		for (int i = 0; i + 2 < C; i++) {
			if (arr[i] == arr[i + 1] && arr[i + 2] == arr[i + 1] + 1)	ans++;
		}
		for (int i = 0; i + 1 < C; i++) {
			if (arr[i] == arr[i + 1] + 1)	ans++;
		}
	}
	else if (type == 4) {
		for (int i = 0; i + 2 < C; i++) {
			if (arr[i + 1] == arr[i + 2] && arr[i] == arr[i + 1] + 1)	ans++;
		}
		for (int i = 0; i + 1 < C; i++) {
			if (arr[i + 1] == arr[i] + 1)	ans++;
		}
	}
	else if (type == 5) {
		for (int i = 0; i + 2 < C; i++) {
			if (arr[i + 1] == arr[i + 2] && arr[i] == arr[i + 1])	ans++;
		}
		for (int i = 0; i + 2 < C; i++) {
			if (arr[i] == arr[i + 2] && arr[i] == arr[i + 1] + 1)	ans++;
		}
		for (int i = 0; i + 1 < C; i++) {
			if (arr[i + 1] == arr[i] + 1)	ans++;
		}
		for (int i = 0; i + 1 < C; i++) {
			if (arr[i] == arr[i + 1] + 1)	ans++;
		}
	}
	else if (type == 6) {
		for (int i = 0; i + 2 < C; i++) {
			if (arr[i + 1] == arr[i + 2] && arr[i] == arr[i + 1])	ans++;
		}
		for (int i = 0; i + 2 < C; i++) {
			if (arr[i + 1] == arr[i + 2] && arr[i + 1] == arr[i] + 1)	ans++;
		}
		for (int i = 0; i + 1 < C; i++) {
			if (arr[i + 1] == arr[i])	ans++;
		}
		for (int i = 0; i + 1 < C; i++) {
			if (arr[i] == arr[i + 1] + 2)	ans++;
		}
	}
	else if (type == 7) {
		for (int i = 0; i + 2 < C; i++) {
			if (arr[i + 1] == arr[i + 2] && arr[i] == arr[i + 1])	ans++;
		}
		for (int i = 0; i + 2 < C; i++) {
			if (arr[i + 1] == arr[i] && arr[i + 1] == arr[i + 2] + 1)	ans++;
		}
		for (int i = 0; i + 1 < C; i++) {
			if (arr[i + 1] == arr[i])	ans++;
		}
		for (int i = 0; i + 1 < C; i++) {
			if (arr[i + 1] == arr[i] + 2)	ans++;
		}
	}
	/*
	if (type == 2) ans *= 4;
	if (type == 1 || type == 3 || type == 4) ans *= 2;
	*/
	cout << ans << endl;
}

int main() {
	cin >> C >> P;
	for (int i = 0; i < C; i++)	cin >> arr[i];
	solve(P);
}