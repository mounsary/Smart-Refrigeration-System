# Smart Refrigeration System

**A cost-effective IoT solution designed to upgrade conventional cold storage rooms, preventing product spoilage and enhancing operational efficiency.**

---

## 💡 The Problem
The fundamental challenge in traditional refrigeration is the lack of real-time electronic data. This leads to inefficient management, potential product spoilage, and a lack of control for the owner. Existing PLC-based smart systems are often too expensive, creating a global gap for an affordable and practical solution.

## ⚙️ The Solution & Features
This project provides a practical and cost-effective solution by transforming standard refrigeration units into smart systems with key features:

- **Real-Time Monitoring:** Uses a **DS18B20 sensor** to provide live temperature readings.
- **Smart Alerts:** Notifies the owner via the **Blynk application** and a **buzzer** if the temperature exceeds a specific limit.
- **Compressor Health Monitor:** A dedicated counter tracks the compressor's runtime (hours of operation), alerting the owner when maintenance (e.g., oil change) is due.
- **Fault Detection:** Sends an alert if a malfunction is detected (via a Cryo-one/Kryon-based anomaly detection).
- **Power Outage Alert:** The **TTGO ESP32 with its built-in battery and integrated SIM800L module** sends SMS alerts in the event of a power cut, ensuring the system remains operational.
- **Local Interface:** A small display on the control box shows the compressor's runtime, providing on-site information for technicians.
- **Remote Control:** The owner can remotely turn the compressor on or off using the **Blynk app**, allowing for control only when needed.

## 🛠️ Components
- **Microcontroller:** TTGO ESP32 (with integrated SIM800L module)
- **Temperature Sensor:** DS18B20
- **Power & Protection:** Optocouplers, relays, voltage converters, fuses, and a capacitor for stable power supply
- **Interface:** Small OLED screen and a buzzer for alerts

## 🚀 Future Features
- **Efficiency Monitoring:** Integrate sensors to measure the motor's efficiency and electricity consumption over time.
- **Predictive Analytics:** Use data to predict potential failures before they occur, enabling proactive maintenance.

---

**Note:** The initial code for this project is available in this repository. Please note that it is still being refined and may be incomplete. Detailed wiring diagrams and final code versions will be added as the project progresses.
