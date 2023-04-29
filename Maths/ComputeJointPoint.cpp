/*
Given a number n, we consider the sequence of numbers such that n is followed
by the sum of n and all of its digits. n-> n+sumOfDigits(n).
For example: 34 is followed by 41 = 34+(3+4).

Our task is the following: given two number s1 and s2, find the intersection number,
of s1 and s2.
For example: 471 -> 483 (471+4+7+1) -> 498 (483+4+8+3) -> 519 (498+4+9+8)
             480 -> 492 (480+4+8+0) -> 507 (492+4+9+2) -> 519 (507+5+0+7)

The intersection number of 471 and 480 is 519.
*/

#include <bits/stdc++.h>
using namespace std;

class Answer{
    private:
    static int sumOfDigits(int n){
        int sum = 0;
        while(n > 0){
            sum += n%10;
            n = n/10;
        }
        return sum;
    }
    public:
    static int computeJointPoint(int s1, int s2){
        int seq1 = s1;
        int seq2 = s2;
        while(seq1!=seq2){
            if(seq1 < seq2){
                seq1+=sumOfDigits(seq1);
            }
            else if(seq1 > seq2){
                seq2+=sumOfDigits(seq2);
            }
        }
        return seq1;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    int s1 = 471;
    int s2 = 480;
    cout << Answer::computeJointPoint(s1,s2) << endl;
    return 0;
}
