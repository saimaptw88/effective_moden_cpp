#include <future>
#include <iostream>
#include <thread>
#include <utility>
#include <vector>

#include "section38.hh"


namespace chapter7 {
namespace section38 {
void calc(int start, std::promise<int> p) {
  int sum = 0;
  for (int i = start; i < start + 10; ++i)
    sum += i;

  p.set_value(sum);
}

void client() {
  std::promise<int> p1, p2, p3;
  std::vector<std::future<int>> futs(3);
  futs[0] = p1.get_future();
  futs[1] = p2.get_future();
  futs[2] = p3.get_future();

  std::thread t1(calc, 2, std::move(p1));
  std::thread t2(calc, 1, std::move(p2));
  std::thread t3(calc, 0, std::move(p3));

  std::cout << futs[0].get() << ", "
            << futs[1].get() << ", "
            << futs[2].get() << ", "
            << std::endl;

  t1.join();
  t2.join();
  t3.join();
}
void execute() {
  std::cout << "SECTION 38" << std::endl;
  client();
}
}; // namespace section38
};  // namespace chapter7
