//https://www.acmicpc.net/problem/1699
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);
	vector<int> dp(N + 1);
	for (int i = 1; i <= N; ++i) {
		dp[i] = i;
		for (int j = 1; j*j <= i; ++j) {
			dp[i] = min(dp[i], dp[i - j*j] + 1);
		}
	}
	printf("%d", dp[N]);

}