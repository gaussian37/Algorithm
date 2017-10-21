#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int N, M;
vi isPrime;

void eratosthenes() {
	isPrime = vi(N+10, 1);
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i*i <= N; ++i) {
		if (isPrime[i] == 1) {					
			for (int j = i+i; j <= N; j+=i) {
				isPrime[j] = 0;
			}
		}
	}
}

int main() {

	N = 1000000;
	eratosthenes();
	while (1) {
		scanf("%d", &M);
		if (M == 0) break;

		for (int i = 2; i * i <= 1000000; ++i) {
			if (isPrime[i] && isPrime[M - i]) {
				printf("%d = %d + %d\n", M, i, M - i);
				break;
			}
		}
	}

}