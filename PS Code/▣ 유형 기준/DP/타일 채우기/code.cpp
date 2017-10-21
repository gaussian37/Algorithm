#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);
	vector<int> dp(N + 1);
	dp[0] = 1;
	for (int i = 2; i <= N; i+=2) {
		dp[i] += 3 * dp[i - 2];
		for (int j = i - 4; j >= 0; j-=2){
			dp[i] += 2 * dp[j];
		}
	}

	printf("%d", dp[N]);
	
}