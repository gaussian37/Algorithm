#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N;
void update(vi& tree, int x, int diff) {
	for (int i = x; i <= N; i += i&-i) {
		tree[i] += diff;
	}
}

int sum(vi&tree, int x) {
	int ans = 0;
	for (int i = x; i > 0; i -= i&-i) {
		ans += tree[i];
	}
	return ans;
}

int main() {
	scanf("%d", &N);
	vi A(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}

	map<int, int> pos;
	for (int i = 0; i < N; ++i) {
		int a;
		scanf("%d", &a);
		pos[a] = i + 1;
	}

	ll ans = 0;
	vi tree(4 * N);
	for (int i = 0; i < N; ++i) {
		int left = pos[A[i]] + 1;
		int right = N;
		ans += ll(sum(tree, right) - sum(tree, left - 1));		
		update(tree, pos[A[i]], 1);
	}

	printf("%lld\n", ans);

}