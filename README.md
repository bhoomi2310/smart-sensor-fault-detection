# Smart Sensor Fault Detection Pipeline

## Overview
This project simulates an embedded-style sensor data pipeline in C for real-time monitoring and fault detection. It mimics how microcontrollers process ADC sensor inputs under resource-constrained environments.

## Features
- Simulates real-time sensor streams (temperature and voltage)
- Applies moving average filtering to reduce noise
- Detects faults using threshold + hysteresis logic:
  - Voltage spikes
  - Thermal drift
  - Sensor flatline (dead sensor)
- Generates timestamped logs (UART-style debug output)

## Motivation
In embedded systems, sensors often produce noisy data and operate under strict constraints. This project models a lightweight, real-time fault detection pipeline similar to firmware used in safety-critical systems.

## Implementation Details
- Language: C (no external libraries)
- Loop-based real-time simulation
- Sliding window filtering for noise suppression
- Threshold + hysteresis to avoid false triggers

## Sample Output
[12:01:02] TEMP: 32.4C | VOLT: 3.3V | STATUS: NORMAL
[12:01:05] TEMP: 85.2C | STATUS: OVERHEAT WARNING
[12:01:08] VOLT: 5.8V | STATUS: VOLTAGE SPIKE

## How to Run
```bash
gcc src/main.c -o sensor
./sensor

```
##Future Improvements
Interrupt-driven simulation
Multi-sensor bus (I2C-style simulation)
Porting to real microcontroller (MSP430/TM4C)
