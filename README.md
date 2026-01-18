# 🧯 IoT Fire Detection & Emergency Dashboard (ESP8266)

A real-time fire detection system using **ESP8266**, **IR Flame Sensor**, and **MQ gas sensor**.
The system monitors flame and gas levels continuously and displays a **full-screen emergency dashboard** accessible from any mobile or laptop on the same Wi-Fi network.

---

## 🔥 Features

* Real-time fire detection using flame and gas sensors
* Full-screen emergency alert dashboard
* Automatic red screen when fire is detected
* Audible buzzer alarm
* Date and time display synchronized using NTP
* Fast dashboard refresh for instant response
* Mobile and laptop compatible
* Professional UI with modern design

---

## 🧩 Components Required

| Component            | Purpose                       |
| -------------------- | ----------------------------- |
| ESP8266 (NodeMCU)    | Controller + WiFi server      |
| IR Flame Sensor      | Detects flame presence        |
| MQ-6 / MQ-7 / MQ-135 | Detects smoke / gas level     |
| Buzzer               | Audio alarm in fire condition |
| USB cable            | Power supply                  |

---

## 🔌 Wiring Diagram (Text)

| Component        | ESP8266 Pin |
| ---------------- | ----------- |
| Flame Sensor DO  | D5          |
| MQ Sensor AO     | A0          |
| Buzzer +         | D6          |
| All GND          | GND         |
| Flame Sensor VCC | 3.3V        |
| MQ Sensor VCC    | VIN (5V)    |

---

## 📌 How It Works

1. The sensors continuously send data to ESP8266.
2. If flame is detected or gas level crosses threshold:

   * System enters **EMERGENCY mode**
   * Dashboard becomes **full-screen red**
   * Buzzer turns ON
3. If no fire:

   * Dashboard shows **SYSTEM NORMAL**
   * Buzzer remains OFF
4. Date and time are shown on the dashboard using NTP time synchronization.

---

## 🧑‍💻 Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/iot-fire-detection-dashboard.git
   ```
2. Open the Arduino IDE and load the code:

   ```bash
   firmware/esp8266_fire_dashboard.ino
   ```
3. Update Wi-Fi credentials in the code:

   ```cpp
   const char* ssid = "YOUR_WIFI_NAME";
   const char* password = "YOUR_WIFI_PASSWORD";
   ```
4. Upload the code to ESP8266.
5. Open Serial Monitor and find the IP address:

   ```
   Connected
   Dashboard IP: 192.168.xx.xx
   ```
6. Open browser on any device connected to the same network and enter the IP.

---

## 🧾 Dashboard Preview

You can add screenshots in the `dashboard/` folder:

* `dashboard/normal_mode.png`
* `dashboard/fire_mode.png`

---

## 📈 Applications

* Restaurant kitchen fire safety
* Server room monitoring
* Industrial fire prevention
* Smart building safety systems

---

## 🚀 Future Enhancements

* MQTT cloud dashboard for remote monitoring
* Multi-zone fire detection
* Event logging with timestamps
* Mobile app version
* SMS or email alert integration

---

## 📄 License

This project is licensed under the **MIT License**.

---


