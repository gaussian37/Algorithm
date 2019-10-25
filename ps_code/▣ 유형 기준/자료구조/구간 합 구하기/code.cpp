#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

vl A, tree;
ll init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = A[start];
	}
	else {
		ll m1 = init(2 * node, start, (start + end) / 2);
		ll m2 = init(2*node + 1, (start + end) / 2 + 1, end);
		return tree[node] = m1 + m2;
	}
}

void update(int node, int start, int end, int i, ll diff) {
	if (i < start || end < i) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(2 * node, start, (start + end) / 2, i, diff);
		update(2 * node + 1, (start + end) / 2 + 1, end, i, diff);
	}
}

ll query(int node, int start, int end, int i, int j) {
	if (j < start || end < i) return 0;
	if (i <= start && end <= j) return tree[node];

	ll m1 = query(2 * node, start, (start + end) / 2, i, j);
	ll m2 = query(2 * node + 1, (start + end) / 2 + 1, end, i, j);
	return m1 + m2;	
}

int main() {
	int  N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	A = vl(N+2);
	tree = vl(N * 4);

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
	}

	init(1, 1, N);
	for (int i = 0; i < M + K; ++i) {
		int x;
		scanf("%d", &x);
		if (x == 1) {
			int y; ll z;
			scanf("%d%lld", &y, &z);
			ll diff = z - A[y];
			A[y] = z;
			update(1, 1, N, y, diff);
		}
		else if(x == 2){
			int y, z;
			scanf("%d%d", &y, &z);
			printf("%lld\n", query(1, 1, N, y, z));
		}
	}
}