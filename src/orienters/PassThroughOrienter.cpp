#include "av_project/orienters/PassThroughOrienter.h"

#include "av_project/states/SpatialState.h"

namespace AV {
template <typename TStateEstimate>
TStateEstimate PassThroughOrienter<TStateEstimate>::orient(
    const TStateEstimate& sensorReadings) {
  return sensorReadings;
}

template class PassThroughOrienter<Spatial2DState>;
}  // namespace AV
