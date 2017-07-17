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

int N;

int main() {

	scanf("%d", &N);
	set<string> s;
	string name, state;
	for (int i = 0; i < N; ++i) {
		cin >> name >> state;
		if (state == "enter") {
			s.insert(name);
		}
		if (state == "leave") {
			s.erase(name);
		}
	}

	for (auto iter = s.rbegin(); iter != s.rend(); ++iter) {
		printf("%s\n", (*iter).c_str());
	}

	return 0;
}