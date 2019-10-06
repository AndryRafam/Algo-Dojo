#include <iostream>
#include <algorithm>
#include <vector>

class Sum{
public:
  void add(std::vector<int> v){
    std::sort(v.begin(),v.end());
    int size = v.size();
    int total = v[size-1]+v[size-2];
    std::cout << total << std::endl;
  }
};

int main(void){
  Sum S;
  std::vector<int> vect;
  std::cout << "Enter the size of the array > ";
  int input; std::cin >> input;
  srand(time(0));
  for (auto i = 0; i < input; i++){
    int p = rand()%100 + 1;
    vect.push_back(p);
  }
  for (auto i : vect)
    std::cout << i << " ";
  std::cout << std::endl;
  S.add(vect);
}
