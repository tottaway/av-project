#pragma once
#include "av_project/sensors/Sensor.h"

namespace AV {

// returns accurate oriented bounding boxs for all of the objects in the
// environemnt
template <typename TEnv>
class SelfSensor : public Sensor<typename TEnv::StateType, TEnv> {
 public:
  typedef Sensor<typename TEnv::StateType, TEnv> BaseType;

  typename TEnv::StateType sense(std::shared_ptr<TEnv> env,
                                 const int agentID) override;
};

}  // namespace AV
