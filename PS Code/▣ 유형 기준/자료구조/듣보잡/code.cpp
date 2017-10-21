#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> ii;

int N, M;

int main() {

	scanf("%d%d", &N, &M);
	set<string> s;
	string str;
	for (int i = 0; i < N; ++i) {
		cin >> str;
		s.insert(str);
	}

	vector<string> ans;
	for (int i = 0; i < M; ++i) {
		cin >> str;
		if (s.count(str) > 0) {
			ans.push_back(str);
		}
	}

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i) {
		printf("%s\n", ans[i].c_str());
	}

	return 0;
}