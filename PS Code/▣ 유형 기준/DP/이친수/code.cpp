#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() {
	
	int N;
	scanf("%d", &N);
	vector<ll> dp(N + 1);

	dp[0] = 1;
	dp[1] = 2;
	for (int i = 3; i <= N; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	printf("%lld\n", dp[N]);
	
}