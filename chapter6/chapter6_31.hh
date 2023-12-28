namespace chapter6 {
namespace _31 {
class Widget {
  public:
    void addFilter() const;

  private:
    int divisor_;
};

void execute();
void addDivisorFilter();

inline int computeSomeValue1() { return 3; }
inline int computeSomeValue2() { return 4; }
inline int computeDivisor(int x, int y) { return x + y; }
};  // namespace _31
};  // namespace chapter6
