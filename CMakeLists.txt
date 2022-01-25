cmake_minimum_required( VERSION 3.10 )

project(av_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(SOURCES 
  src/main.cpp

  src/agents/Simple2DAgent.cpp
  
  src/controllers/PerfectController.cpp

  src/environments/Simple2DEnv.cpp

  src/orienters/PassThroughOrienter.cpp

  src/planners/GoForward2D.cpp

  src/sensors/PerfectSensor.cpp
  src/sensors/SelfSensor.cpp
)

include_directories(./include)

# target
add_executable(av_cli ${SOURCES})

# Eigen as a linear algebra library
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
target_link_libraries(av_cli Eigen3::Eigen)

# yaml-cpp for config files
find_package(yaml-cpp REQUIRED)
target_link_libraries(av_cli yaml-cpp)
