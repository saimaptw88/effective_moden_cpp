#include <iostream>

#include "chapter5/chapter5.hh"
#include "chapter6/chapter6.hh"


int main() {
  std::cout << "hello world" << std::endl;
  chapter5::execute();
  chapter6::execute();

  return 0;
}
