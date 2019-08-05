#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
int sum[1000001];
long long cnt[1001];
long long ans = 0;
int main() {
	memset(cnt, 0, sizeof(cnt));
	cin >> N >> M;
	sum[0] = 0;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		sum[i] = (sum[i - 1] + n) % M;
		if (sum[i] == 0)	ans++;
		cnt[sum[i]]++;
	}
	
	for (int i = 0; i < M; i++) {
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	cout << ans;
}