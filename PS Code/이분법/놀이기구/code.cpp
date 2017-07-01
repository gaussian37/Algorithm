#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> ii;


int main() {

	int N, M;

	scanf("%d%d", &N, &M);
	vi A(M);

	for (int i = 0; i < M; ++i) {
		scanf("%d", &A[i]);
	}

	if (N <= M) {
		printf("%d\n", N);
		return 0;
	}

	ll left = 0;
	ll right = 1e16;

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll begin = 0, end = M;
		
		//mid 분에 탄 사람 수
		for (int i = 0; i < M; ++i) {
			end += mid / A[i];
		}

		begin = end;
		for (int i = 0; i < M; ++i) {
			if (mid % A[i] == 0) {
				begin--;
			}
		}
		begin++;

		if (N < begin) {
			right = mid - 1;
		}
		else if (N > end) {
			left = mid + 1;
		}
		else {
			for (int i = 0; ; ++i) {
				if (mid % A[i] == 0) {
					if (N == begin) {
						printf("%d\n", i + 1);
						return 0;
					}
					begin++;
				}
			}
		}
	}

}