#include <string>
#include <iostream>
using namespace std;
int main() {
    string ans =
        "ABCCCCABCBDDACD"
        "FTTTBA"
        "TTFTCA"
        "TFTTCB"
        "AAAAA"
        "AAAAA";
    int no;
    cin >> no;
    cout << ans[no - 1];
    return 0;
}
