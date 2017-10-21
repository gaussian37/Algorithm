#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {

	int N, M;
	scanf("%d", &N);
#if 1
	
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
		printf("%d ", upper_bound(a.begin(), a.end(), b[i]) 
			- lower_bound(a.begin(), a.end(), b[i]));
	}

#else
    // 시간 초과
	multiset<int> ms;
	int val;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &val);
		ms.insert(val);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d", &val);
		printf("%d ", ms.count(val));
	}

#endif
}