// Given four different points in space. Find whether these points can form a square or not.

#include <iostream>
#include <algorithm>
#include <vector>

class Square{
public:
  Square(void);
  bool isSquare(std::vector<int>& v);
  ~Square(void);
};

Square::Square(void){}

bool Square::isSquare(std::vector<int>& v){
  std::sort(v.begin(), v.end());
  int check1 = 1;
  int check2 = 1;
  for (auto i = 0; i < v.size()/2; ++i){
    if (v[i] == v[i+1]){check1++;}
    if (v[(v.size()-1)-i] == v[(v.size()-1)-i-1]){check2++;}
  }
  if ((check1 == 4)&&(check2 == 4))
    return true;
}

Square::~Square(void){}

int main(void){
  Square *S;
  int x;
  std::vector<int> v;
  for (auto i = 0; i < 8; ++i){
    std::cin >> x;
    v.push_back(x);
  }
  if (S->isSquare(v))
    std::cout << "Square" << std::endl;
  else
    std::cout << "Not Square" << std::endl;
}
