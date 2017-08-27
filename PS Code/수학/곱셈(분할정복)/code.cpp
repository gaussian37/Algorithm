#include <iostream>
using namespace std;

typedef long long ll;
ll mul(long long a, long long b, long long c) {
	if (b == 0) {
		return 1LL;
	}
	else if (b == 1) {
		return a%c;
	}
	else if (b % 2 == 0) {
		long long temp = mul(a, b / 2, c);
		return (temp * temp) % c;
	}
	else {
		return (a * mul(a, b - 1, c)) % c;
	}
}

int main() {
	ll a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	printf("%lld\n", mul(a, b, c));
}
