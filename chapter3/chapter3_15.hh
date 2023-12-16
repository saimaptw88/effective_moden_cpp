#include <array>
#include <iostream>


namespace chapter3 {
namespace _15 {
class Point {
  public:
    constexpr Point(double x = 0, double y = 0) noexcept
    : x_(x), y_(y) {}

    constexpr double x() const noexcept { return x_; }
    constexpr double y() const noexcept { return y_; }

    constexpr void setX(double x) noexcept { x_ = x; }
    constexpr void setY(double y) noexcept { y_ = y; }

  private:
    double x_, y_;
};

constexpr Point midpoint(const Point& p1, const Point& p2) noexcept {
  return { (p1.x() + p2.x()) / 2 + (p1.y() + p2.y()) / 2};
}

constexpr Point reflection(const Point& p) {
  Point result;

  result.setX(- p.x());
  result.setY(- p.y());

  return result;
}

constexpr int pow(int base, int exp) noexcept {
  return (exp == 0 ? 1 : pow(base, exp - 1) * base);
}

constexpr void execute() noexcept {
  constexpr auto numConds = 5;
  constexpr int numElems = pow(3, 5);

  std::array<int, numElems> results;

  constexpr Point p1(9.7, 27.7);
  constexpr Point p2(28.8, 5.3);

  constexpr auto mid = midpoint(p1, p2);
  constexpr auto ref = reflection(mid);
}
};  // namespace _15
};  // namespace chapter3
