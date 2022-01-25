#pragma once
#include <vector>

#include "av_project/agents/Simple2DAgent.h"
#include "av_project/states/SpatialState.h"

namespace AV {

class Simple2DEnv : public std::enable_shared_from_this<Simple2DEnv> {
 public:
  // Relevant types
  typedef Spatial2DState StateType;
  typedef Simple2DAgent<Simple2DEnv> AgentType;

  // Can only be constructed in factory so we don't get shared pointers to stack
  // memory
  [[nodiscard]] static std::shared_ptr<Simple2DEnv> create();

  std::shared_ptr<Simple2DEnv> getptr();

  // TODO load in runtime configs
  void run();
  const std::vector<AgentType>& getAgents() const;

 private:
  // can only be constructed through factory
  Simple2DEnv();
  std::vector<AgentType> m_agents;

  float m_totalTime;
  float m_dt;
  std::size_t m_agentCount;
};

}  // namespace AV
