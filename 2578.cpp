#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void print_vector(vector<T> v)
{
	for (auto each_v : v) {
		cout << each_v << " ";
	}

	cout << endl;
}

#define SIZE 5

bool dap[SIZE][SIZE] = { 0, };

bool input_data(vector<int>(&v)[SIZE], vector<pair<int, int>> &xy_v)
{
	int n = SIZE;
	int each_input;

	if (xy_v.size() < SIZE*SIZE)
		return 1;

	// i, j
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> each_input;

			// check input validation
			if (each_input >= SIZE * SIZE + 1)
				return 1;

			pair<int, int> each_pair = make_pair(i, j);
			xy_v[each_input] = each_pair;

			v[i].push_back(each_input);
		}
	}

	return 0;
}

// 세로 체크
int check_column(int value, vector<pair<int, int>> xy_data)
{
	int ret = 1;
	pair<int, int> xy = xy_data[value];
	for (int i = 0; i < 5; i++) {
		ret &= dap[xy.first][i];
	}

	return ret;
}

// 가로 체크
int check_row(int value, vector<pair<int, int>> xy_data)
{
	int ret = 1;
	pair<int, int> xy = xy_data[value];
	for (int i = 0; i < 5; i++) {
		ret &= dap[i][xy.second];
	}

	return ret;
}

// 대각선 체크
int check_xy(int value, vector<pair<int, int>> xy_data, int orientation)
{
	int ret = 1;
	int i, j;

	for (i = 0; i < 5; i++) {
		ret &= (orientation ? (dap[i][i]) : dap[i][4 - i]);
		if (ret == 0) break;
	}

	return ret;
}

void print_all_data(vector<int>(&v)[SIZE])
{
	int i, j;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << v[i][j] << " ";
		}

		cout << endl;
	}
}

int main()
{
	vector<int> data_array[SIZE];
	vector<int> input;
	vector<pair<int, int>> xy_data(SIZE*SIZE + 1);

	input_data(data_array, xy_data);

	int each_input;
	int x, y;
	int bingo_count = 0;

	for (int i = 0; i < 25; i++)
	{
		cin >> each_input;

		x = xy_data[each_input].first;
		y = xy_data[each_input].second;
		dap[x][y] = true;

		if (x == y) {
			bingo_count += check_xy(each_input, xy_data, true);
		}

		if (x == 4 - y) {
			bingo_count += check_xy(each_input, xy_data, false);
		}

		bingo_count += check_column(each_input, xy_data);
		bingo_count += check_row(each_input, xy_data);

		if (bingo_count >= 3) {
			cout << i + 1;
			return 0;
		}
	}

	return 0;
}