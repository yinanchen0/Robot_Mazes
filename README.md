# Robot_Mazes
Arduino code for a four-wheel robot that autonomously navigates and exits a maze using sensor-based wall detection and timing logic.
![Four-wheel robot maze navigation demo](170-ezgif.com-speed.gif)

# Wall-Following Robot Controller (Arduino)
This project contains Arduino code for a mobile robot that navigates along walls
using a photodiode sensor, push buttons, and multiple motors.
## Overview
- Uses analog photodiode readings to detect wall proximity
- Implements time-based detection (`millis`) to distinguish gaps vs walls
- Controls forward, left, and right motors for navigation
- Maintains internal state flags to manage movement logic

## Key Concepts
- Sensor thresholding
- Finite-state-like logic using flags
- Non-blocking timing with `millis`
- Embedded motor control

## Notes
This code was developed as a learning project and is not fully refactored.
Variable naming and structure reflect experimentation during development.

