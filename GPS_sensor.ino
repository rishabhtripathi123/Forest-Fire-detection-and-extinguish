
#include <TinyGPS.h>
float lat ,lon ; // create variable for latitude and longitude object
SoftwareSerial gpsSerial(3,4);//rx,tx

TinyGPS gps; // create gps object
void setup(){
Serial.begin(9600); // connect serial
Serial.println("The GPS Received Signal:");
gpsSerial.begin(9600); // connect gps sensor

}

void loop(){
while(gpsSerial.available()){ // check for gps data
if(gps.encode(gpsSerial.read()))// encode gps data
{
gps.f_get_position(&lat,&lon); // get latitude and longitude
// display position


Serial.print(lat);
Serial.print(" ");
Serial.print(lon);
Serial.print(" ");


}
}

String latitude = String(lat,6);
String longitude = String(lon,6);
Serial.println(latitude+";"+longitude);
delay(1000);

}
