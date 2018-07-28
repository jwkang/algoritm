#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> d = { 3, 5, 6, 11, 2, 7, 8, 4, 1, 9 };
vector<int> sum_array( d.size(), 0);

void simple_sum()
{
        for (int i = 0; i < d.size(); i++) {
               // calculate part of sum
               sum_array[i] += d[i];
        
               if( i == 0 ) continue;
               sum_array[i] += sum_array[i - 1];
        }

	for ( vector<int>::iterator it = sum_array.begin(); it != sum_array.end(); ++it ) {
		cout << *it << " ";
	}

	cout << endl;
}

void test_it(int from, int to)
{
        if (from < 0 || from >= sum_array.size() ||
               to < 0 || to >= sum_array.size()) {
               cout << "Out of bound !! " << endl;
               return;
        }
        cout << sum_array[to] - sum_array[from] << endl;
}

int main()
{
	simple_sum();
	test_it(4, 6);

	return 0;
}
