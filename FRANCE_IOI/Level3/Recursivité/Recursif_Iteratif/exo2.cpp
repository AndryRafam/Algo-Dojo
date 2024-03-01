#include <iostream>
#include <string>

using namespace std;

void reversePrint(const string& s, int index) {
    if (index >= 0) {
        cout << s[index];
        reversePrint(s, index - 1);
    }
}

int main() {
    string input;
    getline(cin, input);
    reversePrint(input, input.size() - 1);
    return 0;
}


