#pragma once
#include <memory>

namespace AV {

template <typename TResult, typename TEnv>
class Sensor {
 public:
  virtual TResult sense(std::shared_ptr<TEnv> env, const int agentID) = 0;
};

}  // namespace AV
