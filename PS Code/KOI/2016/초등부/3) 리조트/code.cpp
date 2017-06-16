#include <iostream>>
#include <algorithm>
#include <vector>

using namespace std;

int INF = 987654321;
int main() {

	int N, M;
	scanf("%d %d", &N, &M);

	vector<vector<int> > dp(N + 10, vector<int>(2 * (N + 10), INF));
	vector<bool> holiday(N + 10, false);
	
	for (int i = 0; i < M; ++i) {
		int x;
		scanf("%d", &x);
		holiday[x] = true;
	}
	
	dp[0][0] = 0;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= 2 * N; ++j) {
			//1) i+1 일에 리조트에 묵지 않아도 되는 경우
			if (holiday[i+1]) {
				dp[i + 1][j] = dp[i][j];
			}

			//2) i+1 일에 리조트에 묶어야 하는 경우
			//① 쿠폰 사용
			if (j >= 3) {
				dp[i + 1][j - 3] = min(dp[i + 1][j - 3], dp[i][j]);
			}

			//② 1일권 구매
			dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 10000);

			//③ 3일권 구매
			for (int k = 1; k <= 3; ++k) {
				dp[i + k][j + 1] = min(dp[i + k][j + 1], dp[i][j] + 25000);
			}

			//④ 5일권 구매
			for (int k = 1; k <= 5; ++k) {
				dp[i + k][j + 2] = min(dp[i + k][j + 2], dp[i][j] + 37000);
			}

			
		}
	}

	int ans = INF;
	for (int i = 0; i <= 2*N; ++i) {
		ans = min(ans, dp[N][i]);		
	}
	
	printf("%d\n", ans);

}