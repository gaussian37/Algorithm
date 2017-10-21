#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> inorder, postorder, position;

void solve(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe) return;
	int root = postorder[pe];
	printf("%d ", root);
	int p = position[root];

	// inorder : is , p , ie
	// postorder : ps, pe
	// left : p - is
	// right : ie - p

	int left = p - is;
	solve(is, p - 1, ps, ps + left - 1);
	solve(p + 1, ie, ps + left, pe - 1);
}

int main() {
	int N;
	scanf("%d", &N);
	inorder = postorder = position = vector<int>(N + 1);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &inorder[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &postorder[i]);
	}
	for (int i = 0; i < N; i++) {
		position[inorder[i]] = i;
	}
	solve(0, N - 1, 0, N - 1);
}