# AI-Enhanced Health Monitoring System Using ESP32 and Firebase

## Overview
This project involves the development of a real-time, AI-driven health monitoring system that tracks key health parameters such as heart rate, temperature, and body motion. Using ESP32 microcontroller, data is collected from sensors and transmitted to a cloud-based system via Wi-Fi. The system uses Firebase to send real-time notifications to alert healthcare providers or caregivers in case of abnormal readings.

## Features
- **Real-Time Health Monitoring**: Continuous tracking of heart rate, temperature, and motion using health sensors.
- **AI-Based Anomaly Detection**: Implements a machine learning model for predicting abnormal health conditions.
- **Cloud Integration**: Utilizes Firebase for real-time data synchronization and push notifications.
- **Mobile Notifications**: Sends real-time alerts to mobile devices when anomalies are detected.
- **ESP32 with Wi-Fi**: The ESP32 microcontroller enables seamless wireless data transmission.

## Technologies Used
- **Hardware**: 
  - ESP32 microcontroller
  - Health sensors (heart rate, temperature)
- **Software**: 
  - Firebase for cloud services and notifications
  - MicroPython/C for ESP32 programming
  - Python for AI model development
- **Communication**: 
  - Wi-Fi for ESP32 to Firebase communication

## System Architecture
1. **Data Collection**: Health data is gathered using sensors connected to the ESP32.
2. **AI Model**: The AI model processes the sensor data and detects abnormalities.
3. **Firebase Integration**: When an anomaly is detected, the system pushes a notification to Firebase, which sends alerts to the linked mobile app.

## Installation
### Prerequisites
- ESP32 microcontroller
- Health sensors (heart rate, temperature, motion)
- Firebase account
- Python environment (for AI model development)

### Steps
1. Clone this repository:
    ```bash
    git clone https://github.com/yourusername/AI-Health-Monitoring-System.git
    ```
2. Set up the ESP32 with the necessary sensor connections.
3. Flash the ESP32 with the MicroPython code in the `firmware` folder.
4. Configure Firebase:
   - Set up a Firebase project and configure the real-time database.
   - Add Firebase credentials to the code for ESP32 to connect to the cloud.
5. Run the AI model locally or deploy it to an edge device (optional).

## Usage
1. Power on the ESP32 with sensors attached.
2. Monitor health data in real-time on the mobile app.
3. If an anomaly is detected, you will receive a Firebase notification with details.

## Future Enhancements
- Add more health sensors for a broader range of data collection (e.g., blood oxygen level).
- Integrate machine learning inference directly on the ESP32 for faster processing.
- Expand the notification system to include email or SMS alerts.

## Contributing
Contributions are welcome! Please fork the repository and create a pull request with your updates.
