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

int K, N;
vl A;

bool check(ll x) {
	int cnt = 0;
	for (int i = 0; i < K; ++i) {
		cnt += A[i] / x;
	}
	return cnt >= N;
}

int main() {

	scanf("%d%d", &K, &N);
	A = vl(K);

	for (int i = 0; i < K; ++i) {
		scanf("%lld", &A[i]);
	}

	ll ans = 0;
	ll left = 1, right = *max_element(A.begin(), A.end());
	
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (check(mid)) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}

	printf("%lld\n", ans);

}