#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

int N, M, K;
vl tree, A;

ll range_sum(int x) {
	ll ans = 0;
	for (int i = x; i > 0; i -= i&-i) {
		ans += tree[i];
	}
	return ans;
}

void update(int x, ll diff) {
	for (int i = x; i <= N; i += i&-i) {
		tree[i] += diff;
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	A = tree = vl(N + 2);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		update(i, A[i]);
	}

	M += K;
	while (M--) {
		int t1;
		scanf("%d", &t1);
		if (t1 == 1) {
			int t2;
			long long t3;
			scanf("%d %lld", &t2, &t3);
			long long diff = t3 - A[t2];
			A[t2] = t3;
			update(t2, diff);
		}
		else {
			int t2, t3;
			scanf("%d %d", &t2, &t3);
			printf("%lld\n", range_sum(t3) - range_sum(t2 - 1));
		}
	}
	return 0;
}