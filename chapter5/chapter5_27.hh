#ifndef CHAPTER5_CHAPTER5_27_HH_
#define CHAPTER5_CHAPTER5_27_HH_

#include <chrono>
#include <iostream>
#include <set>
#include <string>

#include "../chapter5/chapter5_26.hh"


namespace chapter5 {
namespace _27 {
void execute();
void log();

template <typename T>
void logAndAddImpl(T&& name, std::false_type) {
  auto now = std::chrono::system_clock::now();

  _26::log(now, "logAndAdd");
  _26::names.emplace(std::forward<T>(name));
}

void logAndAddImpl(int idx, std::true_type);

template <typename T>
void logAndAdd(T&& name) {
  logAndAddImpl(std::forward<T>(name),
                std::is_integral<typename std::remove_reference_t<T>>());
}

class Person {
 public:
  template <typename T,
            typename = typename std::enable_if_t<
              !std::is_base_of<std::string, typename std::decay_t<T>>::value
              &&
              !std::is_integral<std::remove_reference_t<T>>::value
            >
           >
  inline explicit Person(T&& n) : name_(std::forward<T>(n)) {
    static_assert(
      std::is_constructible<Person, T>::value,
      "Parameter n can't be used to construct a std::string"
    );
  };

  explicit Person(int idx) : name_(_26::nameFromIdx(idx)) {};

  inline std::string name() {
    return name_;
  }

 private:
  std::string name_;
};
};  // namespace _27
};  // namespace chapter5

#endif  // CHAPTER5_CHAPTER5_27_HH_
