#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	
	vector<ll> dp(s.size() + 10);
	int MOD = 1000000;

	dp[0] = 1;
	int N = s.size();
	s = " " + s;
	for (int i = 1; i <= N; ++i) {
		int x = s[i] - '0';
		// 1자리 암호로 해석하는 방법
		if (1 <= x && x <= 9) {
			dp[i] = (dp[i] + dp[i - 1]) % MOD;
		}

		// 길이가 1인 암호에 해당하므로 길이가 2인 암호는 무시
		if (i == 1) continue;
		// 앞자리가 0인 암호는 길이가 2인 암호가 될 수 없다.
		if (s[i - 1] == '0') continue;
		
		x = (s[i - 1] - '0') * 10 + (s[i] - '0');
		if (10 <= x && x <= 26) {
			dp[i] = (dp[i] + dp[i - 2]) % MOD;
		}
	}
	
	printf("%lld", dp[N]);

	

}