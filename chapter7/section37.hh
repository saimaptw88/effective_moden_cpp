#include <functional>
#include <vector>

namespace chapter7 {
namespace section37 {
bool conditionAreStatisfied();
void performComputation(std::vector<int> val);
bool doWork(std::function<bool(int)> filter, int maxVal);
bool doWorkUpdated(std::function<bool(int)> filter, int maxValue);
void execute();
};  // namespace section37
};  // namespace chapter7
