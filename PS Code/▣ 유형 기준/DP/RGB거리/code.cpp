#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;

int N;
vii A, dp;

int solve(int i, int j) {
	if (i == 0) return 0;

	if (dp[i][j] != -1) return dp[i][j];
	
	dp[i][j] = 1e9;
	if(j==0) dp[i][j] = min(solve(i - 1, 1), solve(i - 1, 2)) + A[i][0];
	if(j==1) dp[i][j] = min(solve(i - 1, 0), solve(i - 1, 2)) + A[i][1];
	if(j==2) dp[i][j] = min(solve(i - 1, 0), solve(i - 1, 1)) + A[i][2];

	return dp[i][j];
}

int main() {

	scanf("%d", &N);
	A = vii(N + 3, vi(3));	
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d%d", &A[i][0], &A[i][1], &A[i][2]);
	}

#if 0
	dp = vii(N + 3, vi(3, -1));
	printf("%d\n", min({ solve(N,0), solve(N,1), solve(N,2) }));

#else

	dp = vii(N + 3, vi(3));
	for (int i = 1; i <= N; ++i) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + A[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + A[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + A[i][2];
	}

	printf("%d\n", min({ dp[N][0], dp[N][1], dp[N][2] }));
	
#endif

}
