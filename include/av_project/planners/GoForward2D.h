#pragma once
#include "av_project/planners/Planner.h"
#include "av_project/states/SpatialState.h"

namespace AV {

class GoForward2D : public Planner<Spatial2DState, Spatial2DState> {
 public:
  typedef Planner<Spatial2DState, Spatial2DState> BaseType;

  Spatial2DState plan(const Spatial2DState &stateEstimate) const override;
};

}  // namespace AV
