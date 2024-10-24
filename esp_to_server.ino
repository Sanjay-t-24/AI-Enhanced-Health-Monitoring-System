#include <WiFi.h>
#include <HTTPClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <MPU6050.h>
#include <PulseSensorPlayground.h>

// Wi-Fi credentials
const char* ssid = "POCO X4 Pro 5G"; #replace with your wifi ssid
const char* password = "Password";

// Server URL
String serverURL = "http://<ip_address>:5000/data"; #Replace with your server ip address

// DS18B20 setup
#define ONE_WIRE_BUS 4 // Pin connected to DS18B20
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Pulse sensor setup
PulseSensorPlayground pulseSensor;
const int pulsePin = 32; // Pin for Pulse sensor

// MPU6050 setup
MPU6050 mpu;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize DS18B20
  sensors.begin();

  // Initialize Pulse sensor
  pulseSensor.analogInput(pulsePin);
  pulseSensor.begin();

  // Initialize MPU6050
  Wire.begin();
  mpu.initialize();
}

void loop() {
  // Get temperature from DS18B20
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);

  // Get heart rate from pulse sensor
  int heartRate = pulseSensor.getBeatsPerMinute();

  // Get MPU6050 data (acceleration and gyro)
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Create data string to send
  String postData = "temperature=" + String(temperature) +
                    "&heart_rate=" + String(heartRate) +
                    "&ax=" + String(ax) + "&ay=" + String(ay) +
                    "&az=" + String(az) + "&gx=" + String(gx) +
                    "&gy=" + String(gy) + "&gz=" + String(gz);

  // Send data to server
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverURL);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpResponseCode = http.POST(postData);
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(response);
    } else {
      Serial.println("Error in sending POST");
    }
    http.end();
  }

  delay(2000); // Send data every 2 seconds
}
