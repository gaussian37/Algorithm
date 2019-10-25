#include <iostream> 

using namespace std;

typedef long long ll;

ll mul(long long a, long long b, long long c) {
	long long ans = 1LL;
	while (b > 0) {
		if (b % 2 == 1) {
			ans *= a;
			ans %= c;
		}
		b /= 2;
		a = a * a;
		a %= c;
	}
	return ans;
}

int main() {
	ll a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	printf("%lld\n", mul(a, b, c));
	return 0;
}