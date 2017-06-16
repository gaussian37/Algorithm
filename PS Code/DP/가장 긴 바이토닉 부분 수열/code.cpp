#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);

	vector<int> A(N), dp1(N), dp2(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; ++i) {
		dp1[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (A[i] > A[j] && dp1[i] < dp1[j] + 1) {
				dp1[i] = dp1[j] + 1;
			}
		}
	}

	for (int i = N - 1; i >= 0; --i) {
		dp2[i] = 1;
		for (int j = i; j < N; ++j) {
			if (A[i] > A[j] && dp2[i] < dp2[j] + 1) {
				dp2[i] = dp2[j] + 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		ans = max(ans, dp1[i] + dp2[i] - 1);
	}

	printf("%d\n", ans);
	
}