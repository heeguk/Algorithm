#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void init(vector<int> &arr, vector<int> &tree, int node, int start, int end)
{
	// start와 end가 같으면 리프 노드. 이때 node에 start idx를 넣는다.
	if (start == end)
		tree[node] = start;

	// start와 end가 다르다면
	else
	{
		int mid = (start + end) / 2;
		init(arr, tree, node * 2, start, mid);
		init(arr, tree, node * 2 + 1, mid + 1, end);


		if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
			tree[node] = tree[node * 2];
		else
			tree[node] = tree[node * 2 + 1];
	}
}

// 구간에서 가장 최소인 높이의 막대 구하기
int query(vector<int> &arr, vector<int> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return -1;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	int m1 = query(arr, tree, node * 2, start, mid, left, right);
	int m2 = query(arr, tree, node * 2 + 1, mid + 1, end, left, right);

	if (m1 == -1)
		return m2;

	else if (m2 == -1)
		return m1;

	else
	{
		if (arr[m1] <= arr[m2])
			return m1;
		else
			return m2;
	}
}

ll getMax(vector<int> &arr, vector<int> &tree, int start, int end)
{
	int n = arr.size();
	int m = query(arr, tree, 1, 0, n - 1, start, end);

	// 넓이 계산
	ll area = (ll)(end - start + 1)*(ll)arr[m];

	// 왼쪽 막대가 존재하냐?
	if (start <= m - 1)
	{
		ll tmp = getMax(arr, tree, start, m - 1);

		if (area < tmp)
			area = tmp;
	}

	// 오른쪽 막대가 존재하나?
	if (m + 1 <= end)
	{
		ll tmp = getMax(arr, tree, m + 1, end);
		if (area < tmp)
			area = tmp;
	}

	// 최대 넓이 반환
	return area;
}

int main()
{
	while (1)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		vector<int> arr(n);

		// 값을 입력 받는다.
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		// 세그 트리 크기를 구한다.
		int h = (int)(ceil(log2(n)));
		int tree_size = (1 << (h + 1));

		vector<int> tree(tree_size);

		// 세그 트리 형성
		init(arr, tree, 1, 0, n - 1);

		printf("%lld\n", getMax(arr, tree, 0, n - 1));
	}

	return 0;
}