#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	int N, K;
	ll MOD = 1000000000;

	scanf("%d%d", &N, &K);
	vector<vector<ll>>dp(K + 10, vector<ll>(N + 10));
	
	dp[0][0] = 1;
	for (int i = 1; i <= K; ++i) {
		for (int j = 0; j <= N; ++j) {
			for (int k = 0; k <= j; ++k) {
				dp[i][j] += dp[i - 1][j - k];
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[4][0] << " " << dp[4][1] << " " << dp[4][2] << " " << dp[4][3] << " " << dp[4][4] << endl;

	printf("%lld", dp[K][N]);

}