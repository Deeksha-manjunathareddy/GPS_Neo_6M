#include <TinyGPS++.h>

// Create a TinyGPS++ object
TinyGPSPlus gps;

void setup() {
  Serial.begin(9600); // Start communication with Serial Monitor
  Serial.println("GPS Module Test - Arduino Uno");
}

void loop() {
  Read data from GPS module (connected to RX pin 0)
  while (Serial.available() ) {
    char c = Serial.read();
    gps.encode(c); // Parse the GPS data

    // Check if valid location data is available
    if (gps.location.isUpdated()) {
      Serial.print("Latitude: ");
      Serial.println(gps.location.lat(), 6); // Latitude with 6 decimal places
      Serial.print("Longitude: ");
      Serial.println(gps.location.lng(), 6); // Longitude with 6 decimal places
    }
  }
}
