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

int N, C;
vl A;

bool check(ll x) {
	ll cnt = 1;
	int last = 0;
	for (int i = 0; i < N; ++i) {
		if (A[i] - A[last] >= x) {
			cnt++;
			last = i;
		}
	}
	return cnt >= C;
}
int main() {

	scanf("%d%d", &N, &C);
	A = vl(N);

	for (int i = 0; i < N; ++i) {
		scanf("%lld", &A[i]);
	}
	sort(A.begin(), A.end());

	ll ans = 0;
	ll left = 1, right = A[N - 1] - A[0];
	
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