#include <functional>
#include <iostream>
#include <memory>
#include <numeric>
#include <utility>
#include <vector>

#include "chapter6_32.hh"


namespace chapter6 {
namespace _32 {
bool Widget::isValidated() const {
  return true;
}

bool Widget::isProcessed() const {
  return true;
}

bool Widget::isArchived() const {
  return true;
}

class IsValAndArch {
  public:
    using DataType = std::unique_ptr<Widget>;

    explicit IsValAndArch(DataType&& ptr) : pw_(std::move(ptr)) {}

    bool operator()() const {
      return pw_->isValidated() && pw_->isArchived();
    }

  private:
    DataType pw_;
};

void execute() {
  // NOTE: 初期化キャプチャ
  auto func = [pw_ = std::make_unique<Widget>()]
              { return pw_->isValidated()
                       && pw_->isArchived(); };

  if (func()) {
    std::cout << "SUCCESS" << std::endl;
  }

  auto func2 = IsValAndArch(std::make_unique<Widget>());

  if (func2()) {
    std::cout << "SUCCESS AGAIN" << std::endl;
  }

  std::vector<double> data;
  for (int i = 0; i < 10; ++i)
    data.push_back(i * 0.1);

  auto func3 = [data_ = std::move(data)](){
    return std::accumulate(data_.begin(), data_.end(), data_.front());
  };

  std::cout << func3() << std::endl;

  std::vector<double> data2;
  for (int i = 0; i < 10; ++i)
    data2.push_back(i * 0.1);

  auto func4 = std::bind(
                  [](const std::vector<double>& data_)
                  {
                    return std::accumulate(data_.begin(), data_.end(), data_.front());
                  },
                  std::move(data2));

  std::cout << func4() << std::endl;

  auto func5 = std::bind([](const std::unique_ptr<Widget>& pw_){
                          return pw_->isArchived() && pw_->isValidated();
                         },
                         std::make_unique<Widget>());
  if (func5()) {
    std::cout << "SUCCESS" << std::endl;
  }
}
};  // namespace _32
};  // namespace chapter6
