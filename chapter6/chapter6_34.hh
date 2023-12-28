#include <chrono>


namespace chapter6 {
namespace _34 {
using Time = std::chrono::steady_clock::time_point;
using Duration = std::chrono::steady_clock::duration;

enum class Sound { Beep, Siren, Whistle };
enum class Volume { Normal, Loud, LoudPlusPlus };

void setAlarm(Time t, Sound s, Duration d);
void setAlarm(Time t, Sound s, Duration d, Volume v);
Time addTimeAndDuration(const Time& tp, const Duration& d);

void execute();
};  // namespace _34
};  // namespace chapter6
