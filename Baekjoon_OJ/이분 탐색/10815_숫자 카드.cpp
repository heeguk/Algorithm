#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[500001];

bool binsearch(int start, int end, int target) {
	if (start > end)
		return false;
	
	int mid = (start + end) / 2;

	if (arr[mid] == target)
		return true;
	else if (target > arr[mid])
		return binsearch(mid + 1, end, target);
	else if (target < arr[mid])
		return binsearch(start, mid - 1, target);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	scanf("%d", &M);
	int target;
	for (int i = 0; i < M; i++) {
		scanf("%d", &target);
		printf("%d ", binsearch(0, N - 1, target));
	}
}