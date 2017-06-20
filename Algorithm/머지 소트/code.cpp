#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;
void merge(int start, int end) {
	vector<int>b(end - start + 1);
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (a[i] <= a[j])b[k++] = a[i++];
		else b[k++] = a[j++];
	}
	while (i <= mid) b[k++] = a[i++];
	while (j <= end) b[k++] = a[j++];
	for (i = start; i <= end; i++) {
		a[i] = b[i - start];
	}

}

void merge_sort(int start, int end) {
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid + 1, end);
	merge(start, end);
}

int main() {

	for (int i = 0; i < 20; ++i) {
		a.push_back(rand()%100);
	}

	merge_sort(0,19);
	for (int i = 0; i < 20; ++i) {
		cout << a[i] << " ";
	}
}