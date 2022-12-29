#include <SoftwareSerial.h>
#include <math.h>

// Constants for the Haversine formula
const double R = 6371; // Earth's radius in kilometers

// Function to calculate the distance between two GPS coordinates using the Haversine formula
double distance(double lat1, double lon1, double lat2, double lon2) {
  double dlat = radians(lat2 - lat1);
  double dlon = radians(lon2 - lon1);
  double a = sin(dlat / 2) * sin(dlat / 2) + cos(radians(lat1)) * cos(radians(lat2)) * sin(dlon / 2) * sin(dlon / 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  double d = R * c;
  return d;
}

// Function to calculate the bearing between two GPS coordinates
double bearing(double lat1, double lon1, double lat2, double lon2) {
  double dlon = radians(lon2 - lon1);
  double lat1r = radians(lat1);
  double lat2r = radians(lat2);
  double y = sin(dlon) * cos(lat2r);
  double x = cos(lat1r) * sin(lat2r) - sin(lat1r) * cos(lat2r) * cos(dlon);
  double bearing = atan2(y, x);
  bearing = degrees(bearing);
  bearing = fmod((bearing + 360),360);
  return bearing;
}

// Create software serial connection to GPS module 1
SoftwareSerial gps1(2, 3); // RX, TX

// Create software serial connection to GPS module 2
SoftwareSerial gps2(4, 5); // RX, TX

// Create software serial connection to GPS module 3
SoftwareSerial gps3(6, 7); // RX, TX

// Initialize variables for GPS coordinates
double lat1 = 0;
double lon1 = 0;
double lat2 = 0;
double lon2 = 0;
double lat3 = 0;
double lon3 = 0;

void setup() {
  // Set baud rate for GPS modules
  gps1.begin(9600);
  gps2.begin(9600);
  gps3.begin(9600);
}

void loop() {
  // Read data from GPS module 1
  if (gps1.available()) {
   
    char c = gps1.read();
    // Check if the current character is a newline
    if (c == '\n') {
      // Check if the GPS sentence is a GPGGA sentence
      if (gps1.find("$GPGGA")) {
        // Parse latitude and longitude from GPS sentence
        lat1 = gps1.parseFloat();
        gps1.read();
        lon1 = gps1.parseFloat();
      }
    }
  }

  // Read data from GPS module 2
  if (gps2.available()) {
    char c = gps2.read();
    // Check if the current character is a newline
    if (c == '\n') {
      // Check if the GPS sentence is a GPGGA sentence
      if (gps2.find("$GPGGA")) {
        // Parse latitude and longitude from GPS sentence
        lat2 = gps2.parseFloat();
        gps2.read();
        lon2 = gps2.parseFloat();
      }
    }
  }

  // Read data from GPS module 3
  if (gps3.available()) {
    char c = gps3.read();
    // Check if the current character is a newline
    if (c == '\n') {
      // Check if the GPS sentence is a GPGGA sentence
      if (gps3.find("$GPGGA")) {
        // Parse latitude and longitude from GPS sentence
        lat3 = gps3.parseFloat();
        gps3.read();
        lon3 = gps3.parseFloat();
      }
    }
  }

  // Calculate distance and bearing between the three GPS modules
  double d12 = distance(lat1, lon1, lat2, lon2);
  double b12 = bearing(lat1, lon1, lat2, lon2);
  double d23 = distance(lat2, lon2, lat3, lon3);
  double b23 = bearing(lat2, lon2, lat3, lon3);
  double d31 = distance(lat3, lon3, lat1, lon1);
  double b31 = bearing(lat3, lon3, lat1, lon1);

  // Calculate average distance and bearing between the three GPS modules
  double d_avg = (d12 + d23 + d31) / 3;
  double b_avg = (b12 + b23 + b31) / 3;

  // Calculate true heading using average distance and bearing
  //double true_heading = (b_avg + d_avg) % 360;
  double true_heading = fmod((b_avg + d_avg), 360);
  // Output true heading to serial monitor
  Serial.println(true_heading);

  // Delay for 1 second
  delay(1000);
}
