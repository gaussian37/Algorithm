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

int main() {

	string s, input;
	cin >> s;

	stack<char>left, right;
	for (int i = 0; i < s.size(); ++i) {
		left.push(s[i]);
	}

	int N;
	scanf("%d", &N);
	while (N--) {
		cin >> input;
		if (input == "L") {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (input == "D") {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (input == "B") {
			if (!left.empty()) {
				left.pop();
			}
		}
		else if(input == "P"){
			char c;
			cin >> c;
			left.push(c);

		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		printf("%c", right.top());
		right.pop();
	}
	
}