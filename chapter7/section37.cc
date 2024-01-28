#include <future>
#include <functional>
#include <iostream>
#include <thread>
#include <utility>
#include <vector>


namespace chapter7 {
namespace section37 {
constexpr auto tenMillion = 10'000'000;

bool conditionAreStatisfied() {
  return true;
}

void performComputation(std::vector<int> val) {
  for (auto&& v : val)
    std::cout << v << std::endl;
}

bool doWork(std::function<bool(int)> filter,
            int maxVal = tenMillion) {
  std::vector<int> goodValues;

  std::thread t([&filter, maxVal, &goodValues]{
    for (auto i = 0; i <= maxVal; ++i) {
      if (filter(i))
        goodValues.push_back(i);
    }
  });

  auto nh = t.native_handle();

  if (conditionAreStatisfied()) {
    t.join();

    performComputation(goodValues);

    return true;
  }

  return false;
}

class ThreadRAII {
  public:
    enum class DtroAction { join, detach };

    ThreadRAII(std::thread&& t, DtroAction a)
    : action_(a), t_(std::move(t)) {}

    ~ThreadRAII()
    {
      if (t_.joinable()) {
        if (action_ == DtroAction::join) {
          t_.join();
        } else {
          t_.detach();
        }
      }
    }

    std::thread& get() { return t_; }

    ThreadRAII(ThreadRAII&&) = default;
    ThreadRAII& operator=(ThreadRAII&&) = default;

  private:
    DtroAction action_;
    std::thread t_;
};

bool doWorkUpdated(std::function<bool(int)> filter,
                   int maxValue=tenMillion)
{
  std::vector<int> goodVals;

  ThreadRAII t(std::thread([&filter, maxValue, &goodVals]{
                             for (auto i = 0; i <= maxValue; ++i) {
                              if (filter(i))
                                goodVals.push_back(i);
                             }}),
               ThreadRAII::DtroAction::join);

  auto nh = t.get().native_handle();

  if (conditionAreStatisfied()) {
    t.get().join();

    performComputation(goodVals);

    return true;
  }

  return false;
}

bool doWorkMoreUpdated(std::function<bool(int)>filter, int maxVal=tenMillion)
{
  std::packaged_task<std::vector<int>()> filterTask([filter=std::move(filter), maxVal]{
                                                      std::vector<int> goodVals;

                                                      for (auto i = 0; i <= maxVal; ++i)
                                                        if (filter(i))
                                                          goodVals.push_back(i);

                                                      return goodVals;
                                                    });

  auto goodValsFuture = filterTask.get_future();

  ThreadRAII t(std::thread(std::move(filterTask)),
               ThreadRAII::DtroAction::detach);

  auto nth = t.get().native_handle();

  if (conditionAreStatisfied()) {
    auto goodVals = goodValsFuture.get();

    performComputation(goodVals);
    return true;
  }

  return false;
}

void execute() {
  std::cout << " *** section 37 ***" << std::endl;

  auto filter = [](int i) {
    if (i < 10)
      return true;

    return false;
  };

  auto done = doWork(filter);
  done |= doWorkUpdated(filter);
  done |= doWorkMoreUpdated(filter);

  std::cout << (done ? "Finish work" : "Still working now") << std::endl;
}
};  // namespace section37
};  // namespace chapter7
