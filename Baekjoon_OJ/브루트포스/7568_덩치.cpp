#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
	int num, weight, height;
	cin >> num;
	pair<int, int> student[50];
	for (int i = 0; i < num; i++) {
		cin >> weight >> height;
		student[i].first = weight;
		student[i].second = height;
	}
	
	for (int i = 0; i < num; i++) {

		int rank = 1;
		for (int j = 0; j < num; j++) {
			if (i == j)
				continue;
			if (student[i].first < student[j].first && student[i].second < student[j].second)
				rank++;
		}
		cout << rank << " ";
	}

	return 0;

}