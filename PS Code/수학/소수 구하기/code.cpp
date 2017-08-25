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

	scanf("%d%d", &M,&N);
	eratosthenes();

	for (int i = M; i <= N; ++i) {
		if (isPrime[i]) {
			printf("%d\n", i);
		}
	}

}