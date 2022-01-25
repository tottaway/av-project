#include "av_project/sensors/SelfSensor.h"

#include "av_project/environments/Simple2DEnv.h"

namespace AV {
template <typename TEnv>
typename TEnv::StateType SelfSensor<TEnv>::sense(std::shared_ptr<TEnv> env,
                                                 const int agentID) {
  auto agents = env->getAgents();
  // TODO bounds check
  return agents[agentID].getState();
}

template class SelfSensor<Simple2DEnv>;
}  // namespace AV
