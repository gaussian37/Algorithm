#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi prime_factor(int N) {
	vi factor;
	for (int i = 2; i*i <= N; ++i) {
		while (N % i == 0) {
			factor.push_back(i);
			N /= i;
		}
	}
	if (N > 1) {
		factor.push_back(N);
	}
	return factor;
}

int main() {

	vi a = prime_factor(100);
	for (int num : a) {
		printf("%d\n", num);
	}
}