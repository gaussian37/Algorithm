#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<vll> vlll;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;

int N;
ll mod = 1000000000;
vlll dp;


ll solve(int i, int j, int s) {
	if (i == 1) {
		if (1 <= j && j <= 9) {
			if (s == (1 << j)) return 1LL;
			else return 0;
		}
		else {
			return 0;
		}
	}

	if (dp[i][j][s] != -1) return dp[i][j][s];

	dp[i][j][s] = 0;
	if (s & (1 << j)) {
		if (j + 1 <= 9) dp[i][j][s] += solve(i - 1, j + 1, s); dp[i][j][s] %= mod;
		if (j - 1 >= 0) dp[i][j][s] += solve(i - 1, j - 1, s); dp[i][j][s] %= mod;
		if (j + 1 <= 9) dp[i][j][s] += solve(i - 1, j + 1, s&~(1 << j)); dp[i][j][s] %= mod;
		if (j - 1 >= 0) dp[i][j][s] += solve(i - 1, j - 1, s&~(1 << j)); dp[i][j][s] %= mod;
	}
	return dp[i][j][s];
}

int main() {

	scanf("%d", &N);
	
#if 1

	dp = vlll(N + 2, vll(10, vl(1 << 10)));
	for (int j = 1; j <= 9; ++j) {
		dp[1][j][1 << j] = 1;
	}

	for (int i = 1; i < N; ++i) {
		for (int j = 0; j <= 9; ++j) {
			for (int k = 0; k < (1 << 10); ++k) {
				if ((k & (1 << j)) != 0) {
					if (j + 1 <= 9) {
						dp[i + 1][j + 1][k | (1 << (j + 1))] += dp[i][j][k];
						dp[i + 1][j + 1][k | (1 << (j + 1))] %= mod;
					}
					if (j - 1 >= 0) {
						dp[i + 1][j - 1][k | (1 << (j - 1))] += dp[i][j][k];
						dp[i + 1][j - 1][k | (1 << (j - 1))] %= mod;
					}
				}
			}
		}
	}

	ll ans = 0;
	for (int j = 0; j <= 9; ++j) {
		ans += dp[N][j][(1 << 10) - 1];
		ans %= mod;
	}
#else
	
	dp = vlll(N + 2, vll(10, vl(1 << 10, -1)));
	ll ans = 0;
	for (int j = 0; j <= 9; ++j) {
		ans += solve(N, j, (1 << 10) - 1);
		ans %= mod;
	}

#endif

	printf("%lld\n", ans);

}