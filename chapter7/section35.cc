#include <future>
#include <iostream>
#include <thread>

#include "section35.hh"


namespace chapter7 {
namespace section35 {
int doAsyncWork() {
  return 3 + 4;
}

void execute() {
  std::cout << " *** SECTION 35 ***"  << std::endl;

  std::thread t(doAsyncWork);
  t.join();

  auto fut = std::async(doAsyncWork);
  std::cout << fut.get() << std::endl;
}
};  // namespace section35
};  // namespace chapter7
