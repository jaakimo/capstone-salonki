#include <Adafruit_BME280.h>
#include <sSense-CCS811.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <ESP8266WiFi.h> 
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>





#define SERIAL_SPEED 19200
#define I2C_ADDR_BME 0x76 // define the BME sensor i2c address
#define I2C_ADDR_CCS 0x5B // define the CCS sensor i2c address

#define IP "https://capstonesalonki.herokuapp.com/api/reading"



// Initialize Wifi, bme and ccs
ESP8266WiFiMulti WiFiMulti;
Adafruit_BME280 bme;
CCS811 ccs;


// Your wifi ssid and password. Change as needed.
const char* ssid = "mokkula_257561"; const char* password = "XXX"; 




// setup code here, to run once:
void setup()


{


  Wire.begin();
  
  // connect to wifi
  Serial.printf("Connecting to %s ", ssid);   
  WiFi.begin(ssid, password); 

  while (WiFi.status() != WL_CONNECTED) 
  {     
    delay(1500); 
    Serial.print("."); 
  } 
  Serial.println(" connected"); 




  Serial.begin(SERIAL_SPEED);
  delay(5000);
  if (!bme.begin(I2C_ADDR_BME))
  {
    Serial.println("Could not find bme sensor!");
    while (1);
  }
  if(!ccs.begin(uint8_t(I2C_ADDR_CCS), uint8_t(CCS811_WAKE_PIN), driveMode_1sec)){
    Serial.println("Could not find ccs sensor!");
    while (1);
  }
  else
  {
    Serial.println("Found sensors");
  }



}







void loop()
{




  int gx, gy, gz, ga, gb;         // raw values
  
  // read raw measurements from device
  
  gx = bme.readTemperature();
  gy = bme.readPressure();
  gz = bme.readHumidity();
  ga = ccs.gettVOC();
  gb = ccs.getCO2();



  if (ccs.checkDataAndUpdate())
  {


    // display  x/y/z/a/b values
    Serial.print("Temperature: ");
    Serial.println(gx);
    Serial.print("Pressure: ");
    Serial.println(gy);
    Serial.print("Humidity: ");
    Serial.println(gz);
    Serial.print("VOC: ");
    Serial.println(ga);
    Serial.print("CO2: ");
    Serial.println(gb);
  }
  else if (ccs.checkForError())
  {
    ccs.printError();
  }

  delay(2000);


  
    

  
  // display values as JSON format
  String json = "{\"sensor\":\"sensor\",\"gx\":\"" + String(gx) + "\",\"gy\":\"" + String(gy) + "\",\"gz\":\"" + String(gz)+ "\"}";

  // send the JSON data as a HTTP POST request
  HTTPClient http;

    Serial.println("[HTTP] begin...");

    http.begin(IP);
    http.addHeader("Content-Type", "application/json");

    int httpcode = http.POST(json);

    if (httpcode == HTTP_CODE_OK)
    {
      Serial.println("Transmission OK");
    }else{
      Serial.println("Transmission failure!");
      Serial.println(httpcode);
    }

  http.end();



}
