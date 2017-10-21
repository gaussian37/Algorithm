#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int main(){
	int N; scanf("%d", &N);
	vector<pi> A(N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld%lld", &A[i].first, &A[i].second);
	}
	sort(A.begin(), A.end());
	vector<ll> B(N);
	B[0] = A[0].second;
	for (int i = 1; i < N; ++i) {
		B[i] = B[i - 1] + A[i].second;
	}

	ll total = B[N - 1];
	auto iter = lower_bound(B.begin(), B.end(), total / 2);
	int idx = iter - B.begin();
	printf("%d\n", A[idx]);
	
	
	
	

		
}
