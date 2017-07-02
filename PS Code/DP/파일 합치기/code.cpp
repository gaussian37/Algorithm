#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> ii;

vi A, psum;
vii dp;

int solve(int i, int j) {
	if (i == j) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	dp[i][j] = 1e9;
	for (int k = i; k <= j - 1; ++k) {
		dp[i][j] = min(dp[i][j], solve(i, k) + solve(k + 1, j) + psum[j] - psum[i - 1]);
	}

	return dp[i][j];
}


int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		int N;
		scanf("%d", &N);

		dp = vii(N + 5, vi(N + 5, -1));
		A = psum = vi(N + 5);
		
		for (int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			psum[i] = psum[i - 1] + A[i];
		}

		printf("%d\n", solve(1, N));

	}

	return 0;
}
