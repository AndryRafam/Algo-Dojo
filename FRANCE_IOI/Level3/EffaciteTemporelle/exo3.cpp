#include <stdio.h>
#include <set>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    int N;
    scanf("%d", &N);

    Point points[N];
    set<pair<int, int>> pointSet;

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
        pointSet.insert({points[i].x, points[i].y});
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((points[i].x + points[j].x) % 2 == 0 && (points[i].y + points[j].y) % 2 == 0) {
                int midX = (points[i].x + points[j].x) / 2;
                int midY = (points[i].y + points[j].y) / 2;
                if (pointSet.count({midX, midY})) {
                    pointSet.erase({midX, midY});
                    count++;
                }
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
