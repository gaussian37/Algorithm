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
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;

int N, M, P;
int start;
vi dp;
vii A;

int solve(int i) {
	if (i == start) return 0;

	if (dp[i] != -1) return dp[i];

	dp[i] = 1e9;
	for (int j = 0; j < N; ++j) {
		for (int k = 0; k < N; ++k) {
			if (j != k && (i & (1 << j)) != 0 && (i & (1 << k)) != 0) {
				dp[i] = min(dp[i], solve(i&~(1 << k)) + A[j][k]);
			}
		}
	}
	return dp[i];
}

int main() {

	scanf("%d", &N);
	A = vii(N, vi(N));
	dp = vi(1 << (N + 2), -1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &A[i][j]);
		}
	}

	string str;
	cin >> str;

	for (int i = N - 1; i >= 0; i--) {
		start = start * 2;
		if (str[i] == 'Y') {
			start += 1;
		}
	}

	scanf("%d", &P);

#if 1
	dp = vi(1 << N, 1e9);
	dp[start] = 0;
	for (int i = 0; i < (1 << N); ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if(j!=k && (i & (1<<j)) != 0 && (i &(1<<k)) == 0 ){
					dp[i | (1 << k)] = min(dp[i | (1 << k)], dp[i] + A[j][k]);
				}

			}
		}
	}

	int ans = 1e9;
	for (int i = 0; i < (1 << N); ++i) {
		if (dp[i] == 1e9) continue;
		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			if ((i & (1 << j)) != 0) {
				cnt++;
			}
		}
		if (cnt >= P) {
			ans = min(ans, dp[i]);
		}
	}

#elif 0
	dp = vi(1 << N, 1e9);
	dp[start] = 0;
	for (int i = 0; i < (1 << N); ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (j != k && (i & (1 << j)) != 0 && (i & (1 << k)) != 0) {
					dp[i] = min(dp[i], dp[i&~(1 << k)] + A[j][k]);
				}

			}
		}
	}

	int ans = 1e9;
	for (int i = 0; i < (1 << N); ++i) {
		if (dp[i] == 1e9) continue;
		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			if ((i & (1 << j)) != 0) {
				cnt++;
			}
		}
		if (cnt >= P) {
			ans = min(ans, dp[i]);
		}
	}
#else
	dp = vi(1 << N, -1);
	int ans = 1e9;
	for (int i = 0; i < (1 << N); ++i) {
		if (solve(i) == 1e9) continue;
		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			if ((i & (1 << j)) != 0) {
				cnt++;
			}
		}

		if (cnt >= P) {
			ans = min(ans, solve(i));
		}
	}

#endif

	if (ans == 1e9) ans = -1;
	printf("%d\n", ans);
}