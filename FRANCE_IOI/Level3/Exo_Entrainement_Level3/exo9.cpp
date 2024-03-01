#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int D;
    cin >> D;

    vector<string> dictionary(D);
    for (int i = 0; i < D; ++i) {
        cin >> dictionary[i];
    }

    int N;
    cin >> N;

    vector<unordered_set<char>> groups(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 4; ++j) {
            char c;
            cin >> c;
            groups[i].insert(c);
        }
    }

    string result;
    for (const string& word : dictionary) {
        if ((int)word.size() != N) continue;
        bool match = true;
        for (int i = 0; i < N; ++i) {
            if (groups[i].count(word[i]) == 0) {
                match = false;
                break;
            }
        }
        if (match) {
            result = word;
            break;
        }
    }

    cout << result << endl;

    return 0;
}
