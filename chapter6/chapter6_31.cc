#include <functional>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "chapter6_31.hh"


namespace chapter6 {
namespace _31 {
using FilterContainer =
  std::vector<std::function<bool(int)>>;

FilterContainer filters;

void Widget::addFilter() const {
  filters.emplace_back(
    [divisor_ = divisor_](int value)
    { return value % divisor_ == 0; }
  );
}

template <class C>
void workWithContaner(const C& container) {
  auto calc1 = computeSomeValue1();
  auto calc2 = computeSomeValue2();

  auto divisor = computeDivisor(calc1, calc2);

  using std::begin;
  using std::end;

  if (std::all_of(
    begin(container), end(container),
    [&](const auto& value)
    { return value % divisor == 0;}
  )) {
    std::cout << "TRUE" << std::endl;
  }

  filters.emplace_back([=](int value) { return value % divisor == 0; });
}


void addDivisorFilter() {
  auto calc1 = computeSomeValue1();
  auto calc2 = computeSomeValue2();

  auto divisor = computeDivisor(calc1, calc2);

  filters.emplace_back(
    [&divisor](int value) { return value % divisor == 0; }
  );
}

void execute() {
  auto pw = std::make_unique<Widget>();

  pw->addFilter();
}
};  // namespace _31
};  // namespace chapter6
