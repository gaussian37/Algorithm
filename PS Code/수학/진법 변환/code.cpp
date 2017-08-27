#include <iostream>
#include <string>
using namespace std;
int main() {
    int ans = 0;
    string s;
    int b;
    cin >> s >> b;
    for (int i=0; i<s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            ans = ans * b + (s[i] - '0');
        } else {
            ans = ans * b + (s[i] - 'A' + 10);
        }
    }
    cout << ans << '\n';
    return 0;
}