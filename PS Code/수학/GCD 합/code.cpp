#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<int> vi;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int M;
		scanf("%d", &M);

		vi A(M);
		for (int j = 0; j < M; ++j) {
			scanf("%d", &A[i]);
		}

		int sum = 0;
		for (int j = 0; j < M; ++j) {
			for (int k = j + 1; k < M; ++k) {
				sum += gcd(A[j], A[k]);
			}
		}
		printf("%d\n", sum);
	}

}