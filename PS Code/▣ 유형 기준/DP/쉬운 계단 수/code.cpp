#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	long long MOD = 1000000000;
	scanf("%lld", &N);
	vector<vector<long long>> dp(N + 1, vector<long long>(11));
	for (int i = 1; i <= 9; ++i) {
		dp[1][i] = 1;
	}
	
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (j >= 1) {
				dp[i][j] += dp[i - 1][j - 1];
			}
			if (j <= 8) {
				dp[i][j] += dp[i - 1][j + 1];
			}
			dp[i][j] %= MOD;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; ++i) {
		ans += dp[N][i];
	}

	ans %= MOD;
	printf("%lld", ans);

}

