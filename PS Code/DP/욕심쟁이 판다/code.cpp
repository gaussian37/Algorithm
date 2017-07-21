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
vii dp, A;

int di[] = { -1, 0, 0, 1 };
int dj[] = { 0, -1, 1, 0 };

int solve(int i, int j){
	
	if (dp[i][j] != -1) return dp[i][j];

	dp[i][j] = 1;
	for (int k = 0; k < 4; ++k) {
		int ni = i + di[k];
		int nj = j + dj[k];

		if (A[ni][nj] > 0 && A[ni][nj] > A[i][j]) {
			dp[i][j] = max(dp[i][j], solve(ni, nj) + 1);
		}
	}
	return dp[i][j];
}

int main() {
	scanf("%d", &N);
	A = dp = vii(N + 2, vi(N + 2, -1));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &A[i][j]);
		}
	}

	int ans = -1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			ans = max(ans, solve(i, j));
		}
	}
	
	printf("%d\n", ans);

}
