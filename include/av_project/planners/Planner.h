#pragma once

namespace AV {

template <typename TStateEstimate, typename TGoalState>
class Planner {
 public:
  // TODO: do I need dt
  virtual TGoalState plan(const TStateEstimate &stateEstimate) const = 0;
};

}  // namespace AV
