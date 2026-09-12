# 4-Channel Audio-Reactive Solenoid Water Fountain

A real-time hydraulic projection installation that translates live multi-channel audio into physical water ripples projected on screen during the live performance of *"Strums and Verses on Sapumal Flowers"*.

Developed in collaboration with **Devin Nimthaka** (TouchDesigner DSP & Python Integration).

![Circuit Diagram](docs/circuit.drawio.png)

## Hardware Architecture & Features
- **Optocoupler Power Isolation:** External 5V supply powering `JD-VCC` isolates relay coil current from the Arduino logic board.
- **Unified Star Grounding:** Shared ground reference across 12V, 5V, and Arduino logic rails preventing floating signal voltage.
- **Hydraulic Bypass Loop:** T-joint assembly maintains continuous pump recirculation during zero-valve states to protect head pressure.
- **Zero-Latency Serial Communications:** Buffer-clearing C++ parser running on Arduino at 115200 baud handling TouchDesigner execution commands.

## Repository Structure
- `src/arduino/` : Embedded C++ receiver sketch.
- `src/touchdesigner/` : Python script for manual diagnostic hardware testing.
- `docs/` : Hardware schematics and circuit topology (`circuit.drawio.png`).
