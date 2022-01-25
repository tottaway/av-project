#pragma once
#include <Eigen/Dense>

namespace AV {

struct Spatial2DState {
  Eigen::Vector2d pos;
  Eigen::Vector2d vel;
};

struct Spatial3DState {
  Eigen::Vector3d pos;
  Eigen::Vector3d vel;
};

}  // namespace AV
