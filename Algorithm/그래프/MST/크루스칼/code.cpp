#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;

struct Edge {
	int start, end, cost;
	bool operator < (const Edge & __Edge) const {
		return cost < __Edge.cost;
	}
};

vi p;
int Find(int x) {
	if (x == p[x]) {
		return x;
	}
	else {
		return p[x] = Find(p[x]);
	}
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	p[x] = y;
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	p = vi(N + 2);
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}

	vector<Edge> A(M);

	for (int i = 0; i<M; i++) {
		scanf("%d %d %d", &A[i].start, &A[i].end, &A[i].cost);
	}
	sort(A.begin(), A.end());

	int ans = 0;
	for (int i = 0; i<M; i++) {
		Edge e = A[i];
		int x = Find(e.start);
		int y = Find(e.end);
		if (x != y) {
			Union(e.start, e.end);
			ans += e.cost;
		}
	}

	printf("%d\n", ans);
	return 0;

}