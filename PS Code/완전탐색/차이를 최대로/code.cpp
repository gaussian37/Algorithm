#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int main() {
	
	int N;
	scanf("%d", &N);
	vi A(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}

	int ans = -1;
	sort(A.begin(), A.end());
	do {
		int sum = 0;
		for (int i = 1; i < N; ++i) {
			sum += abs(A[i] - A[i - 1]);
		}
		ans = max(ans, sum);
	} while (next_permutation(A.begin(), A.end()));
	printf("%d\n", ans);
}