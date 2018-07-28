#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int temp;
	vector<int> input[4];
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> temp;
			input[j].push_back(temp);
		}
	}

	vector<int> left_array;
	vector<int> right_array;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			left_array.push_back(input[0][i] + input[1][j]);
		}
	}

	sort(left_array.begin(), left_array.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			right_array.push_back(input[2][i] + input[3][j]);
		}
	}

	long long ret = 0;
	vector<int>::iterator lb;
	vector<int>::iterator ub;

	for (auto v : right_array) {
		lb = lower_bound(left_array.begin(), left_array.end(), -v);
		ub = upper_bound(left_array.begin(), left_array.end(), -v);
		ret += (distance(left_array.begin(), ub) - distance(left_array.begin(), lb));
	}

	cout << ret << endl;
	return 0;
}
