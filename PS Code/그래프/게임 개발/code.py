//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//typedef long long ll;
//typedef vector<int> vi;
//typedef vector<vector<int>> vii;
//typedef vector<ll> vl;
//typedef vector<vl> vll;
//typedef pair<int, int> ii;
//
////vi a;
////vii dp;
////vii check;
////
////int min = -32768 * 101;
////
////int solve(int n, int m) {
////	if (m == 0) {
////		return 0;
////	}
////	if (n <= 0) {
////		return min;
////	}
////	if (c[n][m]) return d[n][m];
////	c[n][m] = true;
////	int &ans = d[n][m];
////	ans = go(n - 1, m);
////	int sum = 0;
////	for (int k = n; k >= 1; k--) {
////		sum += a[k];
////		int temp = go(k - 2, m - 1) + sum;
////		if (ans < temp) ans = temp;
////	}
////	return ans;
////}
//
////int main() {
////	int n, m;
////	scanf("%d %d", &n, &m);
////	for (int i = 1; i <= n; i++) {
////		scanf("%d", &a[i]);
////	}
////	printf("%d\n", go(n, m));
////	return 0;
////}
//
//
//int main() {
//	int N, M;
//	scanf("%d%d", &N, &M);
//
//	vi A(N + 5);
//	vii dp(N + 5, vi(M + 5, -32768*N));
//	vi psum(N + 5);
//
//	for (int i = 1; i <= N; ++i) {
//		scanf("%d", &A[i]);
//	}
//	/*for (int i = 0; i <= N; ++i) {
//		dp[i][0] = 0;
//	}
//	for (int j = 0; j <= M; ++j) {
//		dp[0][j] = 0;
//	}*/
//
//	psum[1] = A[1];
//	for (int i = 2; i <= N; ++i) {
//		psum[i] = psum[i - 1] + A[i];
//	}
//
//	dp[1][1] = A[1];
//	for (int i = 1; i <= N; ++i) {
//		for (int j = 1; j <= M; ++j) {
//			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
//
//			for (int k = 2; k < i; ++k) {
//				if (k == 2) {
//					dp[i][j] = max(dp[i][j], psum[i] - psum[k - 1]);
//				}
//				else {
//					dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + psum[i] - psum[k - 1]);
//				}
//				
//			}
//		}
//	}
//
//	for (int i = 1; i <= N; ++i) {
//		for (int j = 1; j <= M; ++j) {
//			cout << dp[i][j] << " ";
//		}cout << endl;
//	}
//	printf("%d\n", dp[N][M]);
//}