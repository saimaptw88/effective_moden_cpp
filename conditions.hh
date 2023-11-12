#ifndef CONDITIONS_HH_
#define CONDITIONS_HH_

class Widget {
 public:
  Widget() = default;
  Widget(int x, int y) : x_(x), y_(y) {}

  int x() const noexcept { return x_; }
  int y() const noexcept { return y_; }

 private:
  int x_, y_;
};

#endif  // CONDITIONS_HH_
