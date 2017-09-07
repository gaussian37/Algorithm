#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int N;
vii tree;
int range_sum(int x, int y) {
	int ans = 0;
	for(int i = x; i > 0; i -= i & -i){
		for (int j = y; j > 0; j -= j & -j) {
			ans += tree[i][j];
		}
	}
	return ans;
}

int update(int x, int y, int diff) {
	for (int i = x; i <= N; i+= i & -i) {
		for (int j = y; j <= N; j += j & -j) {
			tree[i][j] += diff;
		}
	}
}