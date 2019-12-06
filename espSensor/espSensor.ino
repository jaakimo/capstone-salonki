
#include <Adafruit_BME280.h>
#include <sSense-CCS811.h>


#define SERIAL_SPEED 19200
#define I2C_ADDR_BME 0x77 // define the BME sensor i2c address
#define I2C_ADDR_CCS 0x5B // define the CCS sensor i2c address

Adafruit_BME280 bme;
CCS811 ccs;

void setup()
{
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
  if (ccs.checkDataAndUpdate())
  {
    Serial.print("Temperature: ");
    Serial.println(bme.readTemperature());
    Serial.print("Pressure: ");
    Serial.println(bme.readPressure());
    Serial.print("Humidity: ");
    Serial.println(bme.readHumidity());
    Serial.print("VOC: ");
    Serial.println(ccs.gettVOC());
    Serial.print("CO2: ");
    Serial.println(ccs.getCO2());
  }
  else if (ccs.checkForError())
  {
    ccs.printError();
  }

  delay(2000);
}
