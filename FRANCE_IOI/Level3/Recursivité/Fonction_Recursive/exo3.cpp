#include <bits/stdc++.h>
using namespace std;

vector<string> triangle;

void sierpinski(int x, int y, int size) {
    if (size == 1) {
        triangle[y][x] = '#';
    } else {
        size /= 2;
        sierpinski(x, y, size);
        sierpinski(x + size, y, size);
        sierpinski(x, y + size, size);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    triangle = vector<string>(N, string(N, ' '));

    sierpinski(0, 0, N);

    for (auto& line : triangle) {
        line.erase(line.find_last_not_of(' ') + 1);
        cout << line << '\n';
    }

    return 0;
}



