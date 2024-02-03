#include <list>
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <vector>

#include "section42.hh"


namespace chapter8 {
namespace section42 {
class Widget {
  public:
    Widget(): num_(0) {};
    Widget(int num): num_(num) {}

  private:
    int num_;
};

void execute() {
  std::cout << "SECTUION 42" << std::endl;

  std::vector<std::string> vec;
  vec.push_back("string");
  vec.emplace_back(50, 's');

  std::string queenOfDisco("Donna Summer");
  vec.push_back(queenOfDisco);
  vec.emplace_back(queenOfDisco);

  for (auto&& s : vec) std::cout << s << std::endl;

  std::list<std::shared_ptr<Widget>> ptrs;

  std::shared_ptr<Widget> spw (new Widget);
  ptrs.push_back(std::move(spw));

  std::vector<std::regex> regexes;
  regexes.emplace_back(nullptr);
}
};  // namespace section42
};  // namespace chapter8
