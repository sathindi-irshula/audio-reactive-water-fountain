# 4-Channel Audio-Reactive Solenoid Water Fountain

An interactive hydraulic projection installation that translates live multi-channel audio into physical water ripples projected on screen in real time. 

This repository documents **Phase 1** of the system architecture, developed for the live stage performance of *"Strums and Verses on Sapumal Flowers"*.

---

## Authors & Collaborative Roles

* **Sathindi Irshula:** Hardware System Architecture, Circuit Schematic Design, Hydraulic Distribution Assembly, and Embedded Arduino (C++) Firmware Development.
* **Devin Nimthaka:** TouchDesigner DSP Network Architecture, Multi-Frequency Band Separation, Audio Spectrum CHOP Configuration, and Python Serial Automation.

---

## Core System Architecture & Mechanics

The system operates as an end-to-end real-time loop converting acoustic frequency amplitudes into physical fluid mechanics, which are then optically magnified and projected onto a performance canvas.

```text
┌─────────────────────────┐
│ Live Audio Signal Input │
└────────────┬────────────┘
             │
             ▼
┌─────────────────────────┐
│ TouchDesigner (Python)  │  • Real-time FFT spectrum analysis via Audio Spectrum CHOP
│   DSP Processing Engine │  • Audio split into 4 discrete frequency channels
└────────────┬────────────┘  • Dynamic thresholding converts amplitude peaks into triggers
             │
             ▼
┌─────────────────────────┐
│ Serial Bus (115200 Baud)│  • Low-latency raw string transmission
└────────────┬────────────┘
             │
             ▼
┌─────────────────────────┐
│ Arduino Uno R3 (C++)    │  • High-frequency hardware serial buffer parser
│  Embedded Controller    │  • 5V Active-LOW digital outputs (Pins 2–5)
└────────────┬────────────┘
             │
             ▼
┌─────────────────────────┐
│ Optocoupled Relay Board │  • Optical isolation via JD-VCC rail
│  (4-Channel Module)     │  • Prevents solenoid flyback spikes from resetting MCU
└────────────┬────────────┘
             │
             ▼
┌─────────────────────────┐
│ 12V Solenoid Valves     │  • High-speed hydraulic actuation
│  & Submersible Pump     │  • T-joint pressure relief loop maintains continuous pump head
└────────────┬────────────┘
             │
             ▼
┌─────────────────────────┐
│ Water Reservoir Tank    │  • Jet impact generates overlapping transverse wave patterns
└────────────┬────────────┘
             │
             ▼
┌─────────────────────────┐
│ Optical Refraction Path │  • Surface ripples act as dynamic fluid lenses (Snell's Law)
│  & Screen Projection    │  • High-contrast wave shadows projected onto live display screen
└─────────────────────────┘
