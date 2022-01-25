#pragma once
#include <memory>

namespace AV {

template <typename TEnv, typename TSensor, typename TOrienter,
          typename TPlanner, typename TController>
class Agent {
 public:
  // TODO move to cpp file
  Agent(std::shared_ptr<TEnv> env) : m_env(env), m_agentID(s_currAgentID) {
    // TODO: does this need to be thread safe
    s_currAgentID++;
  }
  virtual void step(const float dt) = 0;
  int getID() const {return m_agentID;}
  typename TEnv::StateType getState() const {return m_state;}

 protected:
  inline static int s_currAgentID = 0;
  const int m_agentID;
  typename TEnv::StateType m_state;

  std::shared_ptr<TEnv> m_env;
  TSensor m_sensor;
  TOrienter m_orienter;
  TPlanner m_planner;
  TController m_controller;
};

}  // namespace AV
