#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "section41.hh"


namespace chapter8 {
namespace section41 {
class Widget {
 public:
  void addName(std::string newName) {
    names.push_back(std::move(newName));
  }

  void setPtr(std::unique_ptr<std::string>&& ptr) {
    p = std::move(ptr);
  }

 private:
  std::vector<std::string> names;
  std::unique_ptr<std::string> p;
};

class Password {
 public:
  explicit Password(std::string pwd)
  : text(std::move(pwd)) {}

  void changeTo(std::string newPwd) {
    text = std::move(newPwd);
  }

 private:
  std::string text;
};

void execute() {
  std::cout << "SECTION 41" << std::endl;

  Widget w;

  std::string name("Bart");
  w.addName(name);
  w.addName(name + "Jenne");

  w.setPtr(std::make_unique<std::string>("Moden C++"));

  std::string initPassword("Supercalifragilisticexpialdocious");
  Password p(initPassword);

  std::string newPassword = "Beware the Jabberwock";
  p.changeTo(newPassword);
}
};  // namespace section41
};  // namespace chapter8
