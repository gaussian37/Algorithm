"https://www.acmicpc.net/problem/1463"

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);
	vector<int> dp(N + 1, 0);
	for (int i = 2; i <= N; ++i) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
			dp[i] = dp[i / 3] + 1;
		else if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
			dp[i] = dp[i / 2] + 1;
	}
	printf("%d", dp[N]);

}