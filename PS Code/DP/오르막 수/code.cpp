#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	int MOD = 10007;
	scanf("%d", &N);
	vector<vector<long long>> dp(N + 10, vector<long long>(11));
	for (int i = 0; i <= 9; ++i) {
		dp[1][i] = 1;
	}
	// dp[i][j] = 길이가 i이고 마지막 수가 j인 오르막 수
	// dp[i][j] = dp[i-1][k] (0<=k<=j)
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= 9; ++j) {
			for (int k = 0; k <= j; ++k) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= MOD;
			}
		}
	}

	long long ans = 0;
	for (int j = 0; j < 10; ++j) {
		ans += dp[N][j];
	}

	ans %= MOD;

	printf("%lld", ans);

}

