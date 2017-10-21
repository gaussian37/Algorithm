#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> ii;

vi A;
int N, M;
int ans = 0;

void solve(int i, int sum) {
	if (i == N) {
		if (sum == M) {
			ans += 1;
		}
		return;
	}
	solve(i + 1, sum + A[i]);
	solve(i + 1, sum);
}
int main() {
	scanf("%d%d", &N, &M);
	A = vi(N + 5);
	for (int i = 0; i<N; i++) {
		scanf("%d", &A[i]);
	}
	
#if 0
	solve(0, 0);
	if (M == 0) ans -= 1;
	printf("%d\n", ans);

#else
	for (int i = 1; i<(1 << N); i++) {
		int sum = 0;
		for (int k = 0; k < N; k++) {
			if (i & (1 << k)) {
				sum += A[k];
			}
		}
		if (sum == M) {
			ans += 1;
		}
	}

	printf("%d\n", ans);
#endif

	return 0;
}