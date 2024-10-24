from flask import Flask, request
import csv
import os
from datetime import datetime

app = Flask(__name__)

# Define CSV file path
csv_file = r'D:\serv\sensor_data.csv'

# Check if the file exists and if it has the correct headers
def check_and_add_headers():
    file_exists = os.path.exists(csv_file)
    if file_exists:
        with open(csv_file, mode='r', newline='') as file:
            reader = csv.reader(file)
            headers = next(reader, None)  # Read the first line (headers)
            # If 'Timestamp' is not in the headers, rewrite the file with correct headers
            if headers and 'Timestamp' not in headers:
                rows = list(reader)  # Read the rest of the file
                with open(csv_file, mode='w', newline='') as file:
                    writer = csv.writer(file)
                    writer.writerow(['Timestamp', 'Temperature (°C)', 'Heart Rate (BPM)', 'AX', 'AY', 'AZ', 'GX', 'GY', 'GZ'])
                    writer.writerows(rows)  # Write the old data back with the new header
    else:
        # If file doesn't exist, create it with headers
        with open(csv_file, mode='w', newline='') as file:
            writer = csv.writer(file)
            writer.writerow(['Timestamp', 'Temperature (°C)', 'Heart Rate (BPM)', 'AX', 'AY', 'AZ', 'GX', 'GY', 'GZ'])

# Ensure headers are correct
check_and_add_headers()

@app.route('/data', methods=['POST'])
def receive_data():
    temperature = request.form.get('temperature')
    heart_rate = request.form.get('heart_rate')
    ax = request.form.get('ax')
    ay = request.form.get('ay')
    az = request.form.get('az')
    gx = request.form.get('gx')
    gy = request.form.get('gy')
    gz = request.form.get('gz')

    # Get the current timestamp
    timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')

    # Append the received data along with the timestamp to the CSV file
    with open(csv_file, mode='a', newline='') as file:
        writer = csv.writer(file)
        writer.writerow([timestamp, temperature, heart_rate, ax, ay, az, gx, gy, gz])

    return "Data Received"

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
