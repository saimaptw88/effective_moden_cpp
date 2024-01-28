#include <atomic>
#include <iostream>

#include "section40.hh"


namespace chapter7 {
namespace section40 {
void volatiled() {
  volatile int vi(0);

  vi = 10;

  ++vi;
  --vi;
}
void execute() {
  std::cout << "SECTION 40" << std::endl;

  std::atomic<int> ai(0);

  ai = 10;

  std::cout << ai;

  ++ai;
  --ai;
}
};  // namespace section40
};  // namespace chapter7
