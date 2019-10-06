#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Rotate{
public:
    Rotate(void);
    void rotation(std::vector<std::string> v1, std::vector<std::string> v2);
    ~Rotate(void);
};

Rotate::Rotate(void){}

void Rotate::rotation(std::vector<std::string> v1, std::vector<std::string> v2){
    v2 = v1;
    sort(v1.begin(),v1.end());
    int index = 0;
    for (auto i = 0; i < v1.size(); i++){
      if (v2[i] == v1[0]){
        std::cout << "Rotation point at index > " << index << std::endl;
        std::cout << "Rotation element is > " << v2[i] << std::endl;
    }
    index++;
  }
}

Rotate::~Rotate(void){}

int main(void){
  Rotate *R;
  std::vector<std::string> v1 {
    "polymorphe",
    "ptolemaic",
    "retrograde",
    "supplant",
    "undulate",
    "xenoepist",
    "asymptote",
    "babka",
    "banoffee",
    "engender",
    "karpatka",
    "othellolagkage",
  };
  std::vector<std::string> v2;
  R->rotation(v1,v2);
}
