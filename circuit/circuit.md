✅ ESP8266 Fire Detection System Wiring
1. IR Flame Sensor
Flame Sensor Pin	ESP8266 Pin
VCC	3.3V
GND	GND
DO (Digital Out)	D5
2. MQ Gas Sensor (MQ-6 / MQ-7 / MQ-135)
MQ Sensor Pin	ESP8266 Pin
VCC	VIN (5V)
GND	GND
AO (Analog Out)	A0

Important: MQ sensors require 5V power for stable readings.

3. Buzzer
Buzzer Pin	ESP8266 Pin
+	D6
-	GND
4. Summary Table (Easy Copy-Paste)
Flame Sensor DO  -> D5
MQ Sensor AO     -> A0
Buzzer +         -> D6
All GND          -> GND
Flame Sensor VCC -> 3.3V
MQ Sensor VCC    -> VIN (5V)

5. How to Verify
Step 1:

Open Serial Monitor
You should see:

Connected
Dashboard IP: 192.168.xx.xx

Step 2:

Open browser
Go to the IP address shown
You will see the dashboard.
