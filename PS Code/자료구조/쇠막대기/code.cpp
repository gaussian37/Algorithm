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

int main() {

	cin >> s;

	int cnt = 0;
	stack<int>st;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') {
			st.push(i);
		}
		else {
			if (i - st.top() == 1) {
				st.pop();
				cnt += st.size();
			}
			else {
				st.pop();
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);
	
}