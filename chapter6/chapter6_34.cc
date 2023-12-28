#include <chrono>
#include <functional>
#include <iostream>

#include "chapter6_34.hh"


namespace chapter6 {
namespace _34 {
void setAlarm(Time t, Sound s, Duration d) {
  return;
}

void setAlarm(Time t, Sound s, Duration d, Volume v) {
  return;
}

Time addTimeAndDuration(const Time& tp, const Duration& d) {
  return tp + d;
}


void execute() {
  std::cout << "section 34" << std::endl;

  auto setSoundL = [](Sound s) {
    using namespace std::chrono;
    using namespace std::literals;

    setAlarm(steady_clock::now() + 1h, s, 30s);
  };

  setSoundL(Sound::Beep);

  using namespace std::chrono;
  using namespace std::literals::chrono_literals;
  using namespace std::placeholders;

  using SetAlarm3ParamType = void(*)(Time t, Sound s, Duration d);

  auto setSoundB = std::bind(static_cast<SetAlarm3ParamType>(setAlarm),
                             std::bind(addTimeAndDuration,
                                       steady_clock::now(),
                                       1h),
                             _1,
                             30s);
  setSoundB(Sound::Beep);

  int lowVal = 0, highVal = 100;

  auto betweenL = [lowVal, highVal](const auto& val) { return val >= lowVal && val <= highVal; };

  if (betweenL(9)) {
    std::cout << 9 << " is between " << lowVal << " and " << highVal << std::endl;
  }

  auto betweenB = std::bind(std::logical_and<bool>(),
                            std::bind(std::less_equal<int>(), lowVal, _1),
                            std::bind(std::less_equal<int>(), _1, highVal));
  if (betweenB(19)) {
    std::cout << 19 << " is between " << lowVal << " and " << highVal << std::endl;
  }
}
};  // namespace _34
};  // namespace chapter6
