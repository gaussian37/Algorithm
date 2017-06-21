#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);

		vector<vector<int> > A(2, vector<int>(N + 10));
		vector<vector<int>> dp(N + 10, vector<int>(3));

		for (int i = 0; i < 2; ++i) {
			for (int j = 1; j <= N; ++j) {
				scanf("%d", &A[i][j]);
			}
		}
			
		for (int i = 1; i <= N; ++i) {
			dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + A[0][i];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + A[1][i];
		}

		printf("%d\n", max({ dp[N][0], dp[N][1], dp[N][2] }));
	}
}