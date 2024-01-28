#ifndef SECTION38_HH_
#define SECTION38_HH_

#include <future>


namespace chapter7 {
namespace section38 {
void calc(int start, std::promise<int> p);
void client();
void execute();
}; // namespace section38
};  // namespace chapter7

#endif  // SECTION38_HH_
