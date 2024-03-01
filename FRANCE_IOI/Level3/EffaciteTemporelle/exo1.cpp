#include <stdio.h>
#include <stack>
using namespace std;

struct Poster {
    int height;
};

int main() {
    int nbRequetes;
    scanf("%d", &nbRequetes);

    stack<Poster> posters;
    int visibleCount = 0;

    for (int i = 0; i < nbRequetes; i++) {
        char type;
        scanf(" %c", &type);

        if (type == 'Q') {
            printf("%d\n", visibleCount);
        } else if (type == 'C') {
            int height;
            scanf("%d", &height);

            while (!posters.empty() && posters.top().height <= height) {
                posters.pop();
            }

            posters.push({height});
            visibleCount = posters.size();
        }
    }

    return 0;
}
