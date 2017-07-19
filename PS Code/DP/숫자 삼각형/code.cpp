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
	if (i == N) return A[i][j];
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = max(solve(i + 1, j), solve(i + 1, j + 1)) + A[i][j];
	return dp[i][j];
}
int main() {

	scanf("%d", &N);
	A = vii(N + 3, vi(N+3));	
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			scanf("%d", &A[i][j]);
		}
	}

	dp = vii(N + 3, vi(N+3, -1));
	printf("%d\n", solve(1, 1));
}
