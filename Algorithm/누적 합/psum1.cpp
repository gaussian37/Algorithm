#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;

int main() {

	int N, M;
	scanf("%d%d", &N, &M);
	vi A(N + 1), psum(N + 1);
	
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
	}

	psum[1] = A[1];
	for (int i = 2; i <= N; ++i) {
		psum[i] = psum[i - 1] + A[i];
	}

	for (int i = 0; i < M; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", psum[y] - psum[x-1]);
	}
}