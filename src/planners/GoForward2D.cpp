#include "av_project/planners/GoForward2D.h"

namespace AV {
Spatial2DState GoForward2D::plan(const Spatial2DState &stateEstimate) const {
  Spatial2DState goalState = stateEstimate;
  goalState.pos[0] += 1;
  return goalState;
}
}  // namespace AV
