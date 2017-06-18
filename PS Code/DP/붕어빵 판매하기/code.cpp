#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);
	vector<int> p(N + 1), dp(N + 1);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &p[i]);
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i] = max(dp[i], dp[i - j] + p[j]);
		}
	}

	printf("%d\n", dp[N]);;

}

