#include <stdio.h>
#include <set>
using namespace std;

int main() {
    int N, P;
    scanf("%d %d", &N, &P);

    set<int> arrived;
    int next = 1;

    for (int i = 0; i < P; i++) {
        int id;
        scanf("%d", &id);
        arrived.insert(id);

        while (arrived.find(next) != arrived.end()) {
            next++;
        }

        if (next <= N) {
            printf("%d\n", next);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}