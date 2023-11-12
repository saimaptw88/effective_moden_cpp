#include "../chapter5/chapter5_27.hh"


namespace chapter5 {
namespace _27 {
void execute() {
  logAndAdd("27::test");
  logAndAdd(27);

  _26::printNames();

  Person p("saito");
  std::cout << p.name() << std::endl;

  Person p2(272);
  std::cout << p2.name() << std::endl;
}

void log(std::chrono::system_clock::time_point t, std::string func_name) {
  _26::log(t, func_name);
}

void logAndAddImpl(int idx, std::true_type) {
  logAndAdd(_26::nameFromIdx(idx));
}
};  // namespace _27
};  // namespace chapter5
