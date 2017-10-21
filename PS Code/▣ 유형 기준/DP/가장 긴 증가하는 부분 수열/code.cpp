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
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (A[j] < A[i] && dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
				//dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int ans = *max_element(dp.begin(), dp.end());
	printf("%d\n", ans);
	
}