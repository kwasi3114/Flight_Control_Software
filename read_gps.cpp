//gps code for flight controller
//tutorial followed: https://randomnerdtutorials.com/esp32-neo-6m-gps-module-arduino/#test-neo-6m-esp32-raw-data


//library for processing raw GPS messages 
#include <TinyGPS++.h>

// Define the RX/TX pins and GPS baud rate
#define RXD2 16
#define TXD2 17
#define GPS_BAUD 9600

// Create an instance of the HardwareSerial class for Serial 2
HardwareSerial gpsSerial(2);

void setup(){
  // Start Serial 2 with the defined RX and TX pins and a baud rate of 9600
  gpsSerial.begin(GPS_BAUD, SERIAL_8N1, RXD2, TXD2);
}

void loop(){
  while (gpsSerial.available() > 0){
    char gpsData = gpsSerial.read();
    gps.encode(gpsSerial.read());
    float latitude = gps.location.lat();
    float longitude = gps.location.lng();
    float altitude = gps.altitude.meters();
  }
}
