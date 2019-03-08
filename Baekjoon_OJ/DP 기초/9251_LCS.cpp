#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int map[16][16];
int dp[1001][1001];
int size_A, size_B;
string A ,B;


int main() {

	cin >> A;
	cin >> B;
	
	size_A = A.length();
	size_B = B.length();

	memset(dp, 0, sizeof(dp));
	
	for (int i = 1; i <= size_A; i++) {
		for (int j = 1; j <= size_B; j++) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[size_A][size_B] << endl;
}