#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

#if 1
	int N;
	scanf("%d", &N);
	vector<int> A(N + 10);
	vector<vector<int>>dp(N + 10, vector<int>(3));

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}

	for (int i = 1; i <= N; ++i) {
		dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
		dp[i][1] = dp[i - 1][0] + A[i];
		dp[i][2] = dp[i - 1][1] + A[i];
	}

	printf("%d", max({ dp[N][0], dp[N][1], dp[N][2] }));

#else

	int N;
	scanf("%d", &N);
	vector<int> A(N + 10);
	vector<int> dp(N + 10);

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}

	dp[1] = A[1];
	dp[2] = A[1] + A[2];
	for (int i = 3; i <= N; ++i) {
		dp[i] = max({ dp[i - 1], dp[i - 2] + A[i], dp[i - 3] + A[i] + A[i - 1] });
	}

	printf("%d\n", dp[N]);

#endif
	
}