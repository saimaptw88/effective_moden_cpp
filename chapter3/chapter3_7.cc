#include <iostream>

#include "chapter3_7.hh"


namespace chapter3 {
class Widget {
  public:
    Widget(int i, bool b);
    Widget(int i, double d);
    Widget(std::initializer_list<long double> il);

    operator float() const;

  private:
    int i_;
    bool b_;
    double d;
};
namespace section7 {
void executive() {
  std::cout << "SECTION 7" << std::endl;
}
};  // namespace section7
};  // namespace chapter3
