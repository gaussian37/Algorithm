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

const long long mod = 100000;
string A;
bool over = false;
//long long dp[200][200];
vll dp;
string open = "({[";
string close = ")}]";

//dp[i][j] = i~j 까지 문자열을 이용해서 만들 수 있는 올바른 괄호 문자열의 개수
ll solve(int i, int j) {
	if (i > j) {
		return 1;
	}

	if (dp[i][j] != -1) return dp[i][j];
	
	dp[i][j] = 0;
	for (int k = i + 1; k <= j; k++) {
		for (int l = 0; l<3; l++) {
			if (A[i] == open[l] || A[i] == '?') {
				if (A[k] == close[l] || A[k] == '?') {
					ll temp = solve(i + 1, k - 1) * solve(k + 1, j);
					if (dp[i][j] + temp > mod) {
						over = true;
					}
					dp[i][j] += temp;
					dp[i][j] %= mod;
				}
			}
		}
	}
	return dp[i][j];
}

int main() {
	int N;
	scanf("%d", &N);
	cin >> A;
	A = " " + A;
	dp = vll(N + 5, vl(N + 5, -1));

	ll ans = solve(1, N);
	if (over) {
		printf("%05lld\n", ans);
	}
	else {
		printf("%lld\n", ans);
	}
	return 0;
}