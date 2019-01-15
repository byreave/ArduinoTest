#include <MPU6050_tockn.h>
#include <Wire.h>

// MPU6050 mpu6050(Wire);

// long timer = 0;

// void setup()
// {
//   Serial.begin(9600);
//   Wire.begin();
//   mpu6050.begin();
//   mpu6050.calcGyroOffsets(true);
//   Serial.setTimeout(5);
//   mpu6050.writeMPU6050(0x6B, false);
// }

// void loop()
// {
//   mpu6050.update();

//   // if (!Serial.available())
//   //   return;

//   // String str = Serial.readString();
//   // if (str == "lines")
//   // {
//   //   Serial.println("This is a line.");
//   //   Serial.println("This is another line");
//   // }
//   if (millis() - timer > 1000)
//   {

//     Serial.println("=======================================================");
//     Serial.print("temp : ");
//     Serial.println(mpu6050.getTemp());
//     Serial.print("accX : ");
//     Serial.print(mpu6050.getAccX());
//     Serial.print("\taccY : ");
//     Serial.print(mpu6050.getAccY());
//     Serial.print("\taccZ : ");
//     Serial.println(mpu6050.getAccZ());

//     Serial.print("gyroX : ");
//     Serial.print(mpu6050.getGyroX());
//     Serial.print("\tgyroY : ");
//     Serial.print(mpu6050.getGyroY());
//     Serial.print("\tgyroZ : ");
//     Serial.println(mpu6050.getGyroZ());

//     Serial.print("accAngleX : ");
//     Serial.print(mpu6050.getAccAngleX());
//     Serial.print("\taccAngleY : ");
//     Serial.println(mpu6050.getAccAngleY());

//     Serial.print("gyroAngleX : ");
//     Serial.print(mpu6050.getGyroAngleX());
//     Serial.print("\tgyroAngleY : ");
//     Serial.print(mpu6050.getGyroAngleY());
//     Serial.print("\tgyroAngleZ : ");
//     Serial.println(mpu6050.getGyroAngleZ());

//     Serial.print("angleX : ");
//     Serial.print(mpu6050.getAngleX());
//     Serial.print("\tangleY : ");
//     Serial.print(mpu6050.getAngleY());
//     Serial.print("\tangleZ : ");
//     Serial.println(mpu6050.getAngleZ());
//     Serial.println("=======================================================\n");
//     timer = millis();
//   }
// }

void setup()
{
  Wire.begin();

  Serial.begin(9600);
  Serial.println("\nI2C Scanner");
}

void loop()
{
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for (address = 1; address < 127; address++)
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknow error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(5000); // wait 5 seconds for next scan
}