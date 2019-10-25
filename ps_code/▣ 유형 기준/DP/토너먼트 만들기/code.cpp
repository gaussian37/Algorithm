#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;

int N;
int INF = 1e9;

vi A;
vii W, dp;

int solve(int i, int j) {
	if (i == j) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	dp[i][j] = INF;
	for (int k = i; k < j; ++k) {
		dp[i][j] = min(dp[i][j], solve(i, k) + solve(k + 1, j) + abs(W[i][k] - W[k + 1][j]));
	}
	return dp[i][j];
}

int main() {
	scanf("%d", &N);
	A = vi(N);
	W = vii(N, vi(N));
	dp = vii(N, vi(N, -1));

	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; ++i) {
		W[i][i] = A[i];
		for (int j = i + 1; j < N; ++j) {
			W[i][j] = min(W[i][j - 1], A[j]);
		}
	}

	printf("%d\n", solve(0, N - 1));
}