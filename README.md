# AV Project

Current design plan
* Simulation
  * contains an environment, objects, agents, sensors
  * handles stepping through time
* Environment
  * worlds with objects and agents in them
  * can be sensed
  * templated sense function
* SimObject:
  * have location, shape, can be sensed, and can update their own state
  * support for collision detection (but probably not resolution since a crash is probably the end of the sim)
* Agent
  * extends SimObject
  * maybe have something like military OODA loop (observe, orient, decide, act)
  * contain sensors, planners, and actuators
* Sensor
  * Handles observations of OODA
  * Mostly a shell which specifies the output type
  * If an environment supports a Sensor you can call env.sense(sensor, loc, time)
* Orienter
  * Handles orient of OODA
  * Takes in sensor results returns a state estimate
* Planner
  * Takes in state estimate and returns a goal state (vector of goal states)
* Controller
  * Takes in goal state and takes actions
  * could be fine-grained like steering the wheel of a car,
    or corse grained like setting the position and velocity of an object directly
  * For now controllers can only update their own state

* Some cases the orient and plan steps might be done in an end to end fashion. In the case, the planner directly takes in the sensor data, we can have the orienter simply pass through sensor data (possibly doing any preprocessing or fusion). In this case the processed sensor data is a sparse representation of a state estimation. In general, the planner should directly take in the result of the orienter and output a goal state.

Pseudo code for agent time step:
```
sensor_results = []
for each sensor:
  // TODO: figure out how exactly sensor's state stays up to date
  sensor_results.appens(sensor.sense(env))

state_estimate = orientor.orient(sensor_results)
goal_state = planner.plan(state_estimate)
controller.act(goal_state)
```

