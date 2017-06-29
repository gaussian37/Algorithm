#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> ii;

int main() {
	string s;
	cin >> s;
	int N = s.size();
	s = " " + s;

	vii dp(N + 5, vi(N + 5));
	for (int i = 1; i <= N; ++i) {
		dp[i][i] = 1;
	}

	for (int i = 1; i <= N; ++i) {
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}

	for (int k = 3; k <= N; ++k) {
		for (int i = 1; i <= N - k + 1; ++i) {
			int j = i + k - 1;
			if (s[i] == s[j] && dp[i + 1][j - 1]) {
				dp[i][j] = 1;
			}
		}
	}

	vi dp2(N + 5, -1);
	dp2[0] = 0;
	for (int i = 1; i <= N; ++i) {
		//dp2[i] = -1;
		for (int j = 1; j <= i; ++j) {
			if (dp[j][i]) {
				if (dp2[i] == -1 || dp2[i] > dp2[j - 1] + 1) {
					dp2[i] = dp2[j - 1] + 1;
				}
			}
		}
	}

	printf("%d\n", dp2[N]);
}