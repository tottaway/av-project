#include "av_project/agents/Simple2DAgent.h"

#include "av_project/environments/Simple2DEnv.h"

namespace AV {

// TODO can I move this to Agent
template<>
void Simple2DAgent<Simple2DEnv>::step(const float dt) {
  auto sensorResults = m_sensor.sense(m_env, m_agentID);
  auto stateEstimate = m_orienter.orient(sensorResults);
  auto goalState = m_planner.plan(stateEstimate);
  m_state = m_controller.act(goalState);
}
}  // namespace AV
