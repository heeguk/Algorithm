#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arrA[1000], arrB[1000];
vector<int> vecA, vecB;

long long get_same(long long index, vector<int>& vec) {
	long long same = 1;

	for (int i = index + 1; i < vec.size(); i++) {
		if (vec[index] == vec[i])	same++;
		else 
			break;
	}
	return same;
}

int main() {
	int T, A, B;
	cin >> T;
	cin >> A;
	for (int i = 0; i < A; i++) {
		cin >> arrA[i];
	}
	cin >> B;
	for (int i = 0; i < B; i++) {
		cin >> arrB[i];
	}

	for (int i = 0; i < A; i++) {
		int local_sum = 0;
		for (int j = i; j < A; j++) {
			local_sum += arrA[j];
			vecA.push_back(local_sum);
		}
	}
	for (int i = 0; i < B; i++) {
		int local_sum = 0;
		for (int j = i; j < B; j++) {
			local_sum += arrB[j];
			vecB.push_back(local_sum);
		}
	}
	sort(vecA.begin(), vecA.end());
	sort(vecB.begin(), vecB.end());
	reverse(vecB.begin(), vecB.end());

	long long left = 0;
	long long right = 0;
	long long ans = 0;
	while (left < vecA.size() && right < vecB.size()) {
		long long sum = vecA[left] + vecB[right];
		if (sum == T) {
			long long left_same = get_same(left, vecA);
			long long right_same = get_same(right, vecB);
			ans += left_same * right_same;
			left += left_same;
			right += right_same;
		}
		else if (sum < T) {
			left++;
		}
		else if (sum > T) {
			right++;
		}
 	}
	cout << ans;
}