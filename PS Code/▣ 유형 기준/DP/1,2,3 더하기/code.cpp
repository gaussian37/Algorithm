#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> dp(12);
	dp[0] = 1;
	for (int i = 1; i <= 10; i++) {
		dp[i] += dp[i - 1];
		if (i >= 2) {
			dp[i] += dp[i - 2];
		}
		if (i >= 3) {
			dp[i] += dp[i - 3];
		}
	}

	int N;
	scanf("%d", &N);
	while (N--) {
		int n;
		scanf("%d\n", &n);
		printf("%d\n", dp[n]);
	}

}

