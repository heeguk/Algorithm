#include <iostream>
#include <cstring>
using namespace std;

int arr[20];
int N;
bool check[2000001];


void solve(int index, int sum) {
	if (index == N) {
		check[sum] = 1;
		return;
	}
	
	solve(index + 1, sum);
	solve(index + 1, sum + arr[index]);
}

int main() {
	memset(check, 0, sizeof(check));
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	solve(0, 0);

	for (int i = 1; i <= 2000001; i++) {
		if (!check[i]) {
			cout << i;
			break;
		}
	}
}