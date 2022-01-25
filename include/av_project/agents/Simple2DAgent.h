#pragma once
#include "av_project/agents/Agent.h"
#include "av_project/controllers/PerfectController.h"
#include "av_project/orienters/PassThroughOrienter.h"
#include "av_project/planners/GoForward2D.h"
#include "av_project/sensors/SelfSensor.h"
#include "av_project/states/SpatialState.h"

namespace AV {

template <typename TEnv>
class Simple2DAgent
    : public Agent<TEnv, SelfSensor<TEnv>,
                   PassThroughOrienter<typename TEnv::StateType>, GoForward2D,
                   PerfectController<typename TEnv::StateType>> {
 public:
  typedef Agent<TEnv, SelfSensor<TEnv>,
                PassThroughOrienter<typename TEnv::StateType>, GoForward2D,
                PerfectController<typename TEnv::StateType>>
      BaseType;

  Simple2DAgent(std::shared_ptr<TEnv> env) : BaseType(env) {}
  void step(const float dt) override;

 private:
};

}  // namespace AV
