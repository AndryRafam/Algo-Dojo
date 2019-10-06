#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

class Max{
public:
  Max();
  void getMax(std::stack<int> s, std::vector<int> v);
  ~Max();
};

Max::Max(){}

void Max::getMax(std::stack<int> s, std::vector<int> v){
  while(!s.empty()){
    v.push_back(s.top());
    s.pop();
  }
  sort(v.begin(),v.end());
  std::cout << "Max stack element is > " << v[v.size()-1] << std::endl;
}

Max::~Max(){}

int main(void){
  Max *M;
  std::stack<int> s;
  std::vector<int> v;
  for (auto i = 0; i < 5; i++){s.push(i);}
  M->getMax(s,v);
}
