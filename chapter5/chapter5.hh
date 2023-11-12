#ifndef CHAPTER5_CHAPTER_HH_
#define CHAPTER5_CHAPTER_HH_

#include <chrono>
#include <iostream>
#include <string>
#include <utility>

#include "../conditions.hh"
#include "../chapter5/chapter5_26.hh"


namespace chapter5 {
void chapter_name();
void execute();

class Annotation {
 public:
  // NOTE: const実引数はmove不可であるため、コピーコンストラクタが呼ばれる(ダメな例)
  explicit Annotation(const std::string text) : text_(std::move(text)) {};
  void text();

 private:
  std::string text_;
};

void makeLogEntry(std::string s, std::chrono::system_clock::time_point t);
void process(const ::Widget& lvalArg);
void process(::Widget&& rvalArg);

class Widget {
 public:
  Widget(std::string s) : s_(std::move(s)) {}
  Widget(Widget&& w) : s_(std::move(w.s_)) { moveCtorCalls_++; }

  inline std::size_t moveCtorCalls() { return moveCtorCalls_; }
  inline std::string s() { return s_; }

 private:
  static std::size_t moveCtorCalls_;
  std::string s_;
};
};  // namespace chapter5

#endif  // CHAPTER5_CHAPTER5_HH_
