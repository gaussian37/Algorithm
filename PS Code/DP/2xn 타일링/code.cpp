#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> v(100);
	for (int i = 0; i < v.size(); ++i) {
		v[i] = rand() % 200;
	}

	sort(v.begin(), v.end());
	int x = 23;

#if 1

	int left = 0, right = v.size() - 1;
	int position = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (v[mid] == x) {
			position = mid;
			break;
		}
		else if (v[mid] > x) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	if (position != -1) {
		cout << position << endl;
		cout << v[position - 1] << " " << v[position] << " " << v[position + 1] << endl;
	}
#else

	//존재 여부 확인
	bool exist = binary_search(v.begin(), v.end(), x);

	//존재 여부 및 위치 확인
	auto iter = lower_bound(v.begin(), v.end(), x);

#endif

}