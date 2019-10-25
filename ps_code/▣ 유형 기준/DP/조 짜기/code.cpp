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
vi A, dp;

int solve(int i) {
	if (i == 0) return 0;

	if (dp[i] != -1) return dp[i];
	dp[i] = 0;

	int mmax = -1;
	int mmin = 1e9;
	for (int j = i; j >= 1; --j) {
		mmax = max(mmax, A[j]);
		mmin = min(mmin, A[j]);
		dp[i] = max(dp[i], solve(j - 1) + (mmax - mmin));
	}
	return dp[i];
}

int main() {
	scanf("%d", &N);
	dp = vi(N + 2, -1);
	A = vi(N + 2);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}

	printf("%d\n", solve(N));
}