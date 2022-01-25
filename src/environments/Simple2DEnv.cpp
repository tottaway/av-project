#include "av_project/environments/Simple2DEnv.h"

#include <iostream>

namespace AV {

[[nodiscard]] std::shared_ptr<Simple2DEnv> Simple2DEnv::create() {
  // Not using std::make_shared<Best> because the c'tor is private.
  return std::shared_ptr<Simple2DEnv>(new Simple2DEnv());
}

std::shared_ptr<Simple2DEnv> Simple2DEnv::getptr() {
  return shared_from_this();
}

Simple2DEnv::Simple2DEnv() {
  m_totalTime = 1.f;
  m_dt = 0.1f;
  m_agentCount = 1;
}


void Simple2DEnv::run() {
  // TODO put agent generation somewhere else??
  for (std::size_t i = 0; i < m_agentCount; i++) {
    m_agents.push_back(AgentType{getptr()});
  }

  for (float t = 0.f; t < m_totalTime; t += m_dt) {
    for (auto& agent : m_agents) {
      agent.step(m_dt);
      std::cout << agent.getState().pos[0] << std::endl;
    }
  }
}

const std::vector<Simple2DEnv::AgentType>& Simple2DEnv::getAgents() const {
  return m_agents;
}

}  // namespace AV
