#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);
	vector<int> A(N), dp(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}
	dp[0] = A[0];
	for (int i = 1; i < N; ++i) {
		dp[i] = max(dp[i - 1] + A[i], A[i]);
	}
	printf("%d\n", *max_element(dp.begin(), dp.end()));
}