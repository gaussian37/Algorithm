#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> ii;

int N;
vii dp;
int solve(int i, int j) {
	if (i == 0 && j == 7) return 1;
	if (i == 0) return 0;

	if (dp[i][j] >= 0) return dp[i][j];

	dp[i][j] = 0;
	if (j == 0) dp[i][j] += solve(i - 1, 7);
	if (j == 1) dp[i][j] += solve(i - 1, 6);
	if (j == 2) dp[i][j] += solve(i - 1, 5);
	if (j == 3) dp[i][j] += solve(i - 1, 4) + solve(i - 1, 7);
	if (j == 4) dp[i][j] += solve(i - 1, 3);
	if (j == 5) dp[i][j] += solve(i - 1, 2);
	if (j == 6) dp[i][j] += solve(i - 1, 1) + solve(i - 1, 7);
	if (j == 7)	dp[i][j] += solve(i - 1, 0) + solve(i - 1, 3) + solve(i - 1, 6);

	return dp[i][j];
}
int main() {
	
	scanf("%d", &N);
	

#if 0
	dp = vii(N + 5, vi(8));
	dp[0][7] = 1;
	for (int i = 1; i <= N; ++i) {
		dp[i][0] = dp[i - 1][7];
		dp[i][1] = dp[i - 1][6];
		dp[i][2] = dp[i - 1][5];
		dp[i][3] = dp[i - 1][4] + dp[i - 1][7];
		dp[i][4] = dp[i - 1][3];
		dp[i][5] = dp[i - 1][2];
		dp[i][6] = dp[i - 1][1] + dp[i - 1][7];
		dp[i][7] = dp[i - 1][0] + dp[i - 1][3] + dp[i - 1][6];
	}

	printf("%d\n", dp[N][7]);

#else
	dp = vii(N + 5, vi(8, -1));
	printf("%d\n", solve(N, 7));

#endif
	return 0;
}