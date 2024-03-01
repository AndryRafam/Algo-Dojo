#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    int I, N;
    cin >> I >> N;

    vector<unordered_set<int>> friends(65000);
    for (int i = 0; i < N; ++i) {
        int I1, I2;
        cin >> I1 >> I2;
        friends[I1].insert(I2);
        friends[I2].insert(I1);
    }

    set<int> friends_of_friends;
    for (int friend_id : friends[I]) {
        for (int friend_of_friend : friends[friend_id]) {
            if (friend_of_friend != I && friends[I].count(friend_of_friend) == 0) {
                friends_of_friends.insert(friend_of_friend);
            }
        }
    }

    cout << friends_of_friends.size() << endl;

    return 0;
}
