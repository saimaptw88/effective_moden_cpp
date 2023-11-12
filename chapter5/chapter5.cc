#include "../chapter5/chapter5.hh"


namespace chapter5 {
void chapter_name() {
  std::cout << "\n***** chapter5 ******" << std::endl;
}

template <typename T>
typename std::remove_reference<T>::type&& move(T&& param) {
  using ReturnType = typename std::remove_reference<T>::type&&;
  return static_cast<ReturnType>(param);
}

template <typename T>
decltype(auto) move_updated(T&& param) {
  using ReturnType = std::remove_reference_t<T> &&;
  return static_cast<ReturnType>(param);
}

template <typename T>
void logAndProcess(T&& param) {
  auto now = std::chrono::system_clock::now();

  makeLogEntry("Calling 'process'", now);

  // NOTE: param自体は実引数のため左辺値.paramが右辺値参照の場合、右辺値にキャストする
  process(std::forward<T>(param));
}

void Annotation::text() {
  std::cout << text_ << std::endl;
}

void makeLogEntry(std::string s, std::chrono::system_clock::time_point t) {
  auto time = std::chrono::system_clock::to_time_t(t);
  std::cout << std::ctime(&time) << " :" << s << std::endl;
}
void process(const ::Widget& lvalArg) {
  std::cout << "lvalue: " << lvalArg.x() << ", " << lvalArg.y() << std::endl;
}
void process(::Widget&& rvalArg) {
  std::cout << "rvalue: " << rvalArg.x() << ", " << rvalArg.y() << std::endl;
}

std::size_t Widget::moveCtorCalls_ = 0;

void execute() {
  chapter_name();

  int x = 10;
  std::cout << move(x) << std::endl;
  std::cout << move_updated(x) << std::endl;

  auto annotation = Annotation("annotation!");
  annotation.text();

  ::Widget w {2, 3};
  logAndProcess(w);
  logAndProcess(std::move(w));

  Widget w1{"test"};
  Widget w2{std::move(w1)};

  std::cout << w1.s() << " " << w2.s() << std::endl;
  std::cout << w1.moveCtorCalls() << std::endl;

  _26::logAndAdd("test");
  _26::logAndAdd(1);

  _26::printNames();
}
};  // namespace chapter5
