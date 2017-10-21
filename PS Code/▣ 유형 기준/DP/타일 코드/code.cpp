#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> ii;

int main() {

	int N; 
	scanf("%d", &N);

	vl dp1(N + 2), dp2(N + 2);
	dp1[1] = 1; dp1[2] = 3;

	for (int i = 3; i <= N; ++i) {
		dp1[i] = dp1[i - 1] + dp1[i - 2] * 2LL;
	}

	dp2[1] = 1;
	dp2[2] = 3;

	for (int i = 3; i <= N; ++i) {
		ll temp = 0;
		if (i % 2 == 1) {
			temp = dp1[(i - 1) / 2];
		}
		else {
			temp = dp1[i / 2] + 2*dp1[(i - 2) / 2];
		}
		dp2[i] = (dp1[i] + temp) / 2;
	}

	printf("%lld\n", dp2[N]);
}