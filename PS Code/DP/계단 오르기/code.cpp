#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);
	vector<int> A(N+1);
	vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}


	dp[1][1] = A[1];
	for (int i = 2; i <= N; ++i) {
		dp[i][1] = max(dp[i - 2][1] + A[i], dp[i - 2][2] + A[i]);
		dp[i][2] = dp[i - 1][1] + A[i];
	}

	printf("%d", max(dp[N][0], dp[N][1]));
	
}