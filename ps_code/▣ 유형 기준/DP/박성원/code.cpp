#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;

int N, M;
vector<string> snum;
vi A, digit;
vll dp;

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {

	scanf("%d", &N);
	snum = vector<string>(N);
	A = vi(N);
	dp = vll(1 << N, vl(100));

	for (int i = 0; i < N; ++i) {
		cin >> snum[i];
	}

	scanf("%d", &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < snum[i].size(); ++j) {
			A[i] = A[i] * 10 + (snum[i][j] - '0');
			A[i] %= M;
		}
	}

	digit = vi(55);
	digit[0] = 1;
	for (int i = 1; i < digit.size(); ++i) {
		digit[i] = digit[i - 1] * 10;
		digit[i] %= M;
	}

	dp[0][0] = 1;
	for (int i = 0; i < (1 << N); ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < N; ++k) {
				if ((i & (1 << k)) == 0) {
					int next = j * digit[snum[k].size()];
					next %= M;
					next += A[k];
					next %= M;
					dp[i | (1 << k)][next] += dp[i][j];
				}
			}
		}
	}

	ll a = dp[(1 << N) - 1][0];
	ll b = 1;
	for (int i = 1; i <= N; ++i) {
		b *= ll(i);
	}
	ll g = gcd(a, b);

	printf("%lld/%lld", a / g, b / g);

}