#pragma once
#include "av_project/controllers/Controller.h"

namespace AV {

template <typename TStateType>
class PerfectController : Controller<TStateType> {
 public:
  TStateType act(const TStateType &goalState) override;
};

}  // namespace AV
