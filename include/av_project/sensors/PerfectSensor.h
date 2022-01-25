#pragma once
#include <vector>

#include "av_project/sensors/Sensor.h"
#include "av_project/util/OBB.h"

namespace AV {

// returns accurate oriented bounding boxs for all of the objects in the
// environemnt
template <typename TEnv>
class PerfectSensor : public Sensor<std::vector<OBB>, TEnv> {
 public:
  typedef Sensor<std::vector<OBB>, TEnv> BaseType;

  std::vector<OBB> sense(std::shared_ptr<TEnv> env,
                         const int agentID) override;
};

}  // namespace AV
