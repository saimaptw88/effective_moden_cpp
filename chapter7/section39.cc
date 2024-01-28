#include <atomic>
#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>


namespace chapter7 {
namespace section39 {
struct ProcessData {
  std::mutex mtx_;
  std::condition_variable cond_;

  bool data_ready_ = false;

 public:
  inline void prepare_data_for_processing() {
    {
      std::lock_guard<std::mutex> lk(mtx_);
      data_ready_ = true;
    }

    cond_.notify_one();
  }

  inline void wait_for_data_to_process() {
    std::unique_lock<std::mutex> lk(mtx_);

    cond_.wait(lk, [this]{return data_ready_;});

    process_data();
  }

 private:
  inline void process_data() {
    std::cout << "process data" << std::endl;
  }
};

void client() {
  ProcessData p;

  std::thread t1 ([&] {p.prepare_data_for_processing();});
  std::thread t2 ([&] {p.wait_for_data_to_process();});

  t1.join();
  t2.join();
}

void execute() {
  std::cout << "SECTION 39" << std::endl;

  client();

  std::condition_variable cv;
  std::mutex m;

  bool flag = false;

  {
    std::lock_guard<std::mutex> g(m);
    flag = true;
  }

  cv.notify_one();

  {
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [&]{return flag;});

    std::cout << "execute" << std::endl;
  }

  std::promise<void> p;
  p.set_value();

  p.get_future().wait();
}
};  // namespace section39
};  // namespace chapter7
