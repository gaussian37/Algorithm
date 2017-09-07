#include <vector>

using namespace std;
typedef vector<int> vi;

int N;
vi tree;
int range_sum(int x) {
	int ans = 0;
	for (int i = x; i > 0; i -= i & -i) {
		ans += tree[i];
	}
	return ans;
}

int update(int x, int diff) {
	for (int i = x; i <= N; i += i & -i) {
		tree[i] += diff;
	}
}