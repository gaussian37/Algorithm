#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

void update(vi& tree, int node, int start, int end, int i, int diff) {
	if (i < start || i > end) return;
	tree[node] += diff;
	if (start != end) {
		update(tree, 2 * node, start, (start + end) / 2, i, diff);
		update(tree, 2 * node + 1, (start + end) / 2 + 1, end, i, diff);
	}
}

int kth(vi& tree, int node, int start, int end, int k) {
	if (start == end) {
		return start;
	}
	else {
		if (k <= tree[2 * node]) {
			return kth(tree, 2 * node, start, (start + end) / 2, k);
		}
		else {
			return kth(tree, 2 * node + 1, (start + end) / 2 + 1, end, k - tree[2*node]);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	int a, b, c;
	int MAX = 1000000;
	vi tree(4*MAX), A(MAX+10);
	while (T--) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d", &b);
			c = kth(tree, 1, 1, MAX, b);
			printf("%d\n", c);
			update(tree, 1, 1, MAX, c, -1);
		}
		else if(a== 2){
			scanf("%d%d", &b, &c);
			update(tree, 1, 1, MAX, b, c);
		}
	}

}