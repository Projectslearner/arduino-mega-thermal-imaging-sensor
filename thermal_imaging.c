/*
    Project name : Thermal Imaging Sensor
    Modified Date: 15-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-thermal-imaging-sensor
*/

#include <Wire.h>
#include <Adafruit_MLX90640.h>

#define MLX90640_I2C_ADDR 0x33 // Default I2C address for MLX90640

Adafruit_MLX90640 mlx;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  Wire.begin(); // Initialize I2C communication
  mlx.begin(); // Initialize MLX90640 sensor

  // Set refresh rate (higher refresh rates require more processing power)
  mlx.setRefreshRate(MLX90640_REFRESH_RATE_2_HZ);
}

void loop() {
  // Check if MLX90640 is ready to read data
  if (mlx.isReady()) {
    // Create buffer to store temperature data
    float mlx90640To[768];

    // Read temperatures from MLX90640 sensor
    mlx.getFrameData(mlx90640To);

    // Print some temperature data to Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(mlx90640To[0]); // Example: Print first temperature value
    Serial.println(" °C");
  } else {
    Serial.println("Error reading MLX90640 sensor data!");
  }

  delay(1000); // Delay before the next reading
}
