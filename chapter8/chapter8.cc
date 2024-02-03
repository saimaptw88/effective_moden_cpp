#include <iostream>

#include "chapter8.hh"
#include "section41.hh"
#include "section42.hh"


namespace chapter8 {
void execute() {
  std::cout << "CHAPTER 8" << std::endl;

  section41::execute();
  section42::execute();
}
};  // namespace chapter8
