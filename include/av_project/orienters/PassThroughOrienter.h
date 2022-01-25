#pragma once
#include "av_project/orienters/Orienter.h"

namespace AV {

// Some sensors (such as PerfectSensor) directly return a state estimate, and
// some planner could directly take sensor reading (an end to end learning
// model) so we want some way of passing things directly through
template <typename TStateEstimate>
class PassThroughOrienter : public Orienter<TStateEstimate, TStateEstimate> {
 public:
  TStateEstimate orient(const TStateEstimate& sensorReadings) override;
};

}  // namespace AV
