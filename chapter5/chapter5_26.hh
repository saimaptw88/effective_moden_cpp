#ifndef CHAPTER5_CHAPTER5_26_HH_
#define CHAPTER5_CHAPTER5_26_HH_

#include <chrono>
#include <iostream>
#include <set>
#include <string>


namespace chapter5 {
namespace _26 {
extern std::multiset<std::string> names;

void log(std::chrono::system_clock::time_point now, std::string func_name);

void logAndAdd(int idx);

template <typename T>
void logAndAdd(T&& name) {
  auto now = std::chrono::system_clock::now();

  log(now, "logAndAdd");
  names.emplace(std::forward<T>(name));
}

std::string nameFromIdx(int idx);
void printNames();
};  // namespace _26
};  // namespace chapter5

#endif  // CHAPTER5_CHAPTER5_26_HH_
