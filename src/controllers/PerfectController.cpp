#include "av_project/controllers/PerfectController.h"

#include "av_project/states/SpatialState.h"

namespace AV {
template <typename TStateType>
TStateType PerfectController<TStateType>::act(const TStateType& goalState) {
  return goalState;
}

template class PerfectController<Spatial2DState>;
}
