#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int main() {
	int N, L;
	scanf("%d%d", &N, &L);
	vi A(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}

	deque<pi> dq;
	vi ans(N);

	for (int i = 0; i < N; ++i) {
		int here = A[i];
		if (!dq.empty() && dq.front().second <= i - L) {
			dq.pop_front();
		}
		while (!dq.empty() && dq.back().first > here) {
			dq.pop_back();
		}

		dq.push_back(pi(here, i));
		ans[i] = dq.front().first;
	}

	for (int num : ans) {
		printf("%d ", num);
	}

}