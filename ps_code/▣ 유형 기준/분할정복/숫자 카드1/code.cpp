#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {

	int N, M;
	scanf("%d", &N);
	
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &a[i]);
	}

	scanf("%d", &M);
	vector<int>b(M);
	for (int i = 0; i < M; ++i) {
		scanf("%d", &b[i]);
	}

	sort(a.begin(), a.end());
	for (int i = 0; i < M; ++i) {
		printf("%d ", binary_search(a.begin(), a.end(), b[i]));
	}

}