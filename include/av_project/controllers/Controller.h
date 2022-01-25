#pragma once

namespace AV {

template <typename TStateType>
class Controller {
  public:
    virtual TStateType act(const TStateType &goalState) = 0;
};

}  // namespace AV
