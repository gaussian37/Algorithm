#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
// a: 배열 a
// tree: 세그먼트 트리
// node: 세그먼트 트리 노드 번호
// node가 담당하는 합의 범위가 start ~ end

typedef long long ll;
typedef vector<ll> vl;
vl A, tree, lazy;

ll init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = A[start];
	}
	else {
		ll m1 = init(node * 2, start, (start + end) / 2);
		ll m2 = init(node * 2 + 1, (start + end) / 2 + 1, end);
		return tree[node] = m1 + m2;
	}
}

void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1)*lazy[node];
		// leaf가 아니면
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int start, int end, int i, int j, ll diff) {
	update_lazy(node, start, end);
	if (i > end || j < start) {
		return;
	}
	if (i <= start && end <= j) {
		tree[node] += (end - start + 1)*diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	update(node * 2, start, (start + end) / 2, i, j, diff);
	update(node * 2 + 1, (start + end) / 2 + 1, end, i, j, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];

}

ll query(int node, int start, int end, int i, int j) {
	update_lazy(node, start, end);
	if (i > end || j < start) {
		return 0;
	}
	if (i <= start && end <= j) {
		return tree[node];
	}
	ll m1 = query(node * 2, start, (start + end) / 2, i, j);
	ll m2 = query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	return  m1 + m2;
}

int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);

	A = vl(N + 2);
	tree = lazy = vl(4 * N);
	M += K;
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
	}

	init(1, 1, N);
	while (M--) {
		int t1, t2, t3;
		scanf("%d", &t1);
		if (t1 == 1) {
			int start, end;
			ll v;
			scanf("%d%d%lld", &start, &end, &v);
			update(1, 1, N, start, end, v);
		}
		else if (t1 == 2) {
			int start, end;
			scanf("%d %d", &start, &end);
			printf("%lld\n", query(1, 1, N, start, end));
		}
	}

	return 0;
}