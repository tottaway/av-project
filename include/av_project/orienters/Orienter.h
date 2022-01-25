#pragma once

namespace AV {

template<typename TSensorReadings, typename TStateEstimate>
class Orienter {
  public:
    virtual TStateEstimate orient(const TSensorReadings &sensorReadings) = 0;
};

} // namespace AV
