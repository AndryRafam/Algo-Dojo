/*Kadane's Algorithm - Max sum sub array*/

#include <bits/stdc++.h>
using namespace std;

class Answer{
public:
  static int max_sum(vector<int> array){
    int best = 0, sum = 0;
    for (auto i = 0; array[i]; i++){
     sum = max(array[i],sum+array[i]);
     best = max(best,sum);
    }
    return best;
  }
};

int main(){
  vector<int> v = {-1,2,4,-3,5,2,-5,2};
  cout << Answer::max_sum(v) << "\n";
}
