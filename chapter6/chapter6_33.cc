#include <iostream>

#include "chapter6_33.hh"


namespace chapter6 {
namespace _33 {
template <class T>
T normalize(T x...) {
  return x;
}

class SomeCompilerGeneratedClassName {
  public:
    template <class T>
    auto operator()(T&& x) const {
      return normalize(std::forward<decltype(x)>(x));
    }
};
void execute() {
  std::cout << "section 33" << std::endl;

  auto func = [](auto&&... x) {
    return normalize(std::forward<decltype(x)>(x)...);
  };

  std::cout << func(1, 2, 3) << std::endl;
}
};  // namespace _33
};  // namespace chapter6
