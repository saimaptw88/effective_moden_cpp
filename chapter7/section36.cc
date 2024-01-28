#include <future>
#include <iostream>
#include <thread>

#include "section36.hh"


namespace chapter7 {
namespace section36 {
template <typename F, typename... Ts>
inline auto realyAsync(F&& f, Ts&&... params) {
  return std::async(std::launch::async,
                    std::forward<F>(f),
                    std::forward<Ts>(params)...);
}

void f() {
  using namespace std::literals;
  std::this_thread::sleep_for(1s);
}

void execute() {
  std::cout << " *** SECTION 36 ***" << std::endl;

  auto fut = std::async(std::launch::deferred, f);

  using namespace std::literals;

  if (fut.wait_for(0s) == std::future_status::deferred) {
    std::cout << "thread not running" << std::endl;
  } else {
    while (fut.wait_for(100ms) != std::future_status::ready) {
      std::cout << "Waiting ..." << std::endl;
    }
  }

  std::cout << "execute" << std::endl;

  auto fut2 = realyAsync(f);

  while (fut2.wait_for(100ms) != std::future_status::ready) {
    std::cout << "Waiting..." << std::endl;
  }

  std::cout << "execute" << std::endl;
}
};  // namespace section36
};  // namespace chapter7
