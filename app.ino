#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

long timer = 0;

void setup()
{
  Serial.begin(250000);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop()
{
  mpu6050.update();

if (millis() - timer > 10)
{
    float userInputZ = cos(mpu6050.getAngleX() / 180.0f * PI) * cos(mpu6050.getAngleY() / 180.0f * PI) - mpu6050.getAccZ();
    float userInputY = mpu6050.getAccY() - sin(mpu6050.getAngleX() / 180.0f * PI);
    Serial.print("UserInputZ: ");
    Serial.println(userInputZ);
    Serial.print("UserInputY: ");
    Serial.println(userInputY);
    timer = millis();
}
    
  //}
  // if (millis() - timer > 300)
  // {

  //   Serial.println("=======================================================");
  //   Serial.print("accX : ");
  //   Serial.print(mpu6050.getAccX());
  //   Serial.print("\taccY : ");
  //   Serial.print(mpu6050.getAccY());
  //   Serial.print("\taccZ : ");
  //   Serial.println(mpu6050.getAccZ());
  //   Serial.print("angleX : ");
  //   Serial.print(mpu6050.getAngleX());
  //   Serial.print("\tangleY : ");
  //   Serial.print(mpu6050.getAngleY());
  //   Serial.print("\tangleZ : ");
  //   Serial.println(mpu6050.getAngleZ());
  //   Serial.println("=======================================================\n");
  //   float userInputZ = cos(mpu6050.getAngleX() / 180.0f * PI) * cos(mpu6050.getAngleY() / 180.0f * PI) - mpu6050.getAccZ();
  //   Serial.print("UserInputZ: ");
  //   Serial.println(userInputZ);
  //   float userInputY = mpu6050.getAccY() - sin(mpu6050.getAngleX() / 180.0f * PI);
  //   Serial.print("UserInputY: ");
  //   Serial.println(userInputY);
  //   timer = millis();
  // }
}

// void setup()
// {
//   Wire.begin();

//   Serial.begin(9600);
//   Serial.println("\nI2C Scanner");
// }

// void loop()
// {
//   byte error, address;
//   int nDevices;

//   Serial.println("Scanning...");

//   nDevices = 0;
//   for (address = 1; address < 127; address++)
//   {
// //     The i2c_scanner uses the return value of
// //     the Write.endTransmisstion to see if
// //     a device did acknowledge to the address.
//     Wire.beginTransmission(address);
//     error = Wire.endTransmission();

//     if (error == 0)
//     {
//       Serial.print("I2C device found at address 0x");
//       if (address < 16)
//         Serial.print("0");
//       Serial.print(address, HEX);
//       Serial.println("  !");

//       nDevices++;
//     }
//     else if (error == 4)
//     {
//       Serial.print("Unknow error at address 0x");
//       if (address < 16)
//         Serial.print("0");
//       Serial.println(address, HEX);
//     }
//   }
//   if (nDevices == 0)
//     Serial.println("No I2C devices found\n");
//   else
//     Serial.println("done\n");

//   delay(5000); // wait 5 seconds for next scan
// }