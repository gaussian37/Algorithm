#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);

	vector<int> A(N), dp(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; ++i) {
		dp[i] = A[i];
		for (int j = 0; j < i; ++j) {
			if (A[j] < A[i] && dp[i] < dp[j] + A[i]){
				dp[i] = dp[j] + A[i];
				//dp[i] = max(dp[i], dp[j] + A[i]);
			}
		}
	}

	int ans = *max_element(dp.begin(), dp.end());
	printf("%d\n", ans);
	
}