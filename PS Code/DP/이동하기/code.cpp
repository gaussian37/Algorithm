#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> dp2, A2;

int solve(int y, int x) {
	if (y == 1 && x == 1) return A2[1][1];
	if (y < 1 || x < 1) return 0;

	if (dp2[y][x] >= 0) return dp2[y][x];

	dp2[y][x] = max({ solve(y - 1, x), solve(y, x - 1), solve(y - 1, x - 1) }) +A2[y][x];
	return dp2[y][x];
}

int main() {

	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<int> > A, dp;
	A = dp = vector<vector<int>>(N + 10, vector<int>(M + 10));


#if 0
	//bottom up 1
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%d", &A[i][j]);
		}
	}
	
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + A[i][j];
		}
	}
	
	printf("%d\n", dp[N][M]);

#elif 0
	//bottom up 2
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + A[i][j];
		}
	}

	printf("%d\n", dp[N][M]);


#elif 1

	A2 = vector<vector<int>>(N + 10, vector<int>(M + 10));
	dp2 = vector<vector<int>>(N + 10, vector<int>(M + 10, -1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%d", &A2[i][j]);
		}
	}

	printf("%d\n", solve(N,M));

#endif

}

