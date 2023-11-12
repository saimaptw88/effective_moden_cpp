#include "../chapter5/chapter5_26.hh"


namespace chapter5 {
namespace _26 {
std::multiset<std::string> names;

void log(std::chrono::system_clock::time_point now, std::string func_name) {
  auto time = std::chrono::system_clock::to_time_t(now);
  auto time_stamp = std::ctime(&time);
  std::cout << time_stamp << func_name << std::endl;
}

void logAndAdd(int idx) {
  auto now = std::chrono::system_clock::now();

  log(now, "logAndAdd");
  names.emplace(nameFromIdx(idx));
}

std::string nameFromIdx(int idx) {
  return "test" + std::to_string(idx);
}

void printNames() {
  for (auto&& name : names)
    std::cout << name << std::endl;
}
};  // namespace _26
};  // namespace chapter5
