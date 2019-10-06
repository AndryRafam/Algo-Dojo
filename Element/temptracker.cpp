#include <iostream>
#include <algorithm>
#include <vector>

class TempTracker{
public:
  TempTracker();
  int getMax(std::vector<int> v);
  int getMin(std::vector<int> v);
  double getMean(std::vector<int> v);
  int getMode(std::vector<int> v);
  ~TempTracker();
};

TempTracker::TempTracker(){}

int TempTracker::getMax(std::vector<int> v){
  int max = *std::max_element(v.begin(),v.end());
  std::cout << "Max temp so far is > " << max << std::endl;
}

int TempTracker::getMin(std::vector<int> v){
  int min = *std::min_element(v.begin(),v.end());
  std::cout << "Min temp so far is > " << min << std::endl;
}

double TempTracker::getMean(std::vector<int> v){
  int sum = 0;
  double mean;
  for (auto &i : v){
    sum += v[i];
  }
  mean = double(sum) / double(v.size());
  std::cout << "Mean is > " << mean << std::endl;
}

TempTracker::~TempTracker(){}

int TempTracker::getMode(std::vector<int> v){
  sort(v.begin(),v.end());
  int max_count = 1, res = v[0], current_count = 1;
  for (auto &i : v){
    if (v[i]==v[i-1])
      current_count ++;
    else if (current_count > max_count){
      max_count = current_count;
      res = v[i-1];
      current_count = 1;
    }
  }
  if (current_count > max_count){
    max_count = current_count;
    res = v[v.size()-1];
  }
  std::cout << "Mode is > " << res << std::endl;
}

int main(void){
  TempTracker *T;
  int tmp;
  std::vector<int> v;
  std::cout << "Input a temperature > ";
  for (auto i = 0; i < 5; i++){
    std::cin >> tmp;
    v.push_back(tmp);
  }
  T->getMax(v);
  T->getMin(v);
  T->getMean(v);
  T->getMode(v);

  return 0;
}
