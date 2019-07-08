#include <iostream>
#include <algorithm>
using namespace std;

long long N, M;
long long target;
long long arr[10001];
long long answer = 0;
void binsearch(long long start, long long end, long long target) {
	if (start > end)
			return ;
	

	long long mid = (start + end) / 2;
	long long result = 0;

	for (int i = 0; i < N; i++) {
		result += arr[i] / mid;
	}


	if (result >= target){
		answer = mid;
		binsearch(mid + 1, end, target);
	}
	else if (result < target){
		binsearch(start, mid - 1, target);
	}
}

int main()
{
	scanf("%lld %lld", &N, &target);
	long long max;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);

		if (i == 0)
			max = arr[i];
		else {
			if (arr[i] > max)
				max = arr[i];
		}
	}
	binsearch(1, max, target);

	printf("%lld\n", answer);
}