#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> ii;

string s;
int N;

int main() {

	scanf("%d", &N);
	while (N--) {
		cin >> s;
		stack<int> st;

		bool ok = true;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				st.push(i);
			}
			else {
				if (st.empty()) {
					ok = false;
					break;
				}
				else {
					st.pop();
				}
			}
		}
		if (st.empty() && ok) {
			puts("YES");
		}
		else {
			puts("NO");
		}
	}
}