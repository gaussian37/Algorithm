/*
작성자: gaussian37
참조글: https://gaussian37.github.io/math-algorithm-trie/
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 자식 노드의 갯수로 총 단어의 갯수에 해당합니다.
// 만약 숫자만 있으면 (0 ~9) 사이즈는 10, 알파벳 소문자만 있으면 26으로 정하면 됩니다.
const int char_size = 26;

// Trie vector의 element
struct Node {
	// 실제 단어에 해당하는 노드인지 유무
	bool valid;
	// char_size 만큼의 크기를 가지는 자식 노드
	vector<int> children;

	Node() {
		valid = false;
		children.assign(char_size, -1);
	}
};

// trie vector를 초기화 합니다.
// root를 생성하고 root의 node 번호는 0이 됩니다.
int Init(vector<Node>& trie) {
	Node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}

// 문자열s가 입력되면 trie에 구성합니다.
void Add(vector<Node>& trie, int node, string& s, int index) {
	// index는 trie에서의 depth에 해당합니다.
	// index(depth)가 문자열의 길이와 같아지면 이 노드에 입력된 문자열을 할당합니다.
	if (index == s.size()) {
		trie[node].valid = true;
		return;
	}

	// 현재 인덱스에 해당하는 문자를 숫자로 매칭시킵니다.
	int c = s[index] - 'a';
	// 현재 노드의 자식 노드 중 c에 해당하는 노드가 생성되지 않았다면 생성합니다.
	if (trie[node].children[c] == -1) {
		// trie에 새로운 노드를 생성해 주고 그 노드의 번호를 리턴 받습니다.
		int next = Init(trie);
		// 리턴 받은 노드 번호를 c번 자식 노드에 할당해 줍니다.
		trie[node].children[c] = next;
	}

	// 아직 index가 문자열 전체 길이만큼 탐색하지 않았으므로 문자열의 다음 인덱스를 탐색합니다.
	// 즉, trie에서 더 깊은 depth 까지 문자열을 구성하는 작업을 재귀를 통하여 반복합니다.
	Add(trie, trie[node].children[c], s, index + 1);
}

// trie에서 특정 문자열 s를 찾는 작업을 합니다.
// trie를 사전에 구성하였기 때문에 O(문자열 s의 길이)만에 찾을 수 있습니다.
bool TrieSearch(vector<Node>& trie, int node, string& s, int index) {
	//문자열 인덱스의 길이 만큼 trie를 탐색한 경우,
	if (index == s.size()) {		
		// 현재 노드의 valid가 유효하다면 단어가 존재합니다.
		if (trie[node].valid) {		
			return true;
		}
		else {
			return false;
		}
	}

	bool ret = false;
	int c = s[index] - 'a';
	// c번 자식 노드가 구성되어 있다면 계속 트리를 탐색합니다.
	// 만약 구성되지 않았다면 trie에 찾는 문자열은 없습니다.
	if (trie[node].children[c] != -1) {
		ret = TrieSearch(trie, trie[node].children[c], s, index + 1);
	}

	return ret;
}

int main() {

	// Trie를 만들 전체 단어 셋
	vector<string> dic = { "a", "to", "tea", "ted", "i", "in", "inn" };

	// 테스트 해 볼 단어 셋
	vector<string> test = { "a", "to", "inn", "tee", "aee", "vae"};
	
	// Trie를 저장할 vector
	vector<Node> trie;
	// Trie 초기화를 위한 root 삽입
	int root = Init(trie);
	// 단어셋을 Trie에 삽입
	for(auto word : dic){
		Add(trie, root, word, 0);
	}
	
	// 테스트 단어 셋을
	for (auto word : test) {
		cout << word << ": ";
		if (TrieSearch(trie, root, word, 0)) {
			cout<<"Exist"<< endl;
		}
		else {
			cout<<"Not exist"<<endl;
		}
	}
}