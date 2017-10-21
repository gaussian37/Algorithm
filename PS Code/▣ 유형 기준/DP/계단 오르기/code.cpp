#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);
	vector<int> A(N + 1);

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}

#if 1
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
	dp[1][1] = A[1];
	for (int i = 2; i <= N; ++i) {
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + A[i];
		dp[i][2] = dp[i - 1][1] + A[i];
	}

	printf("%d", max(dp[N][1], dp[N][2]));

#else

	vector<int>dp(N + 1);
	dp[1] = A[1];
	dp[2] = A[1] + A[2];
	for (int i = 3; i <= N; ++i) {
		dp[i] = max(dp[i - 2] + A[i], dp[i - 3] + A[i - 1] + A[i]);
	}

	printf("%d\n", dp[N]);

#endif


}