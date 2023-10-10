#include"BluetoothSerial.h"
#include<ESP32Servo.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run 'make menuconfig' to and enable it
#endif

BluetoothSerial SerialBT;
Servo myServo;

void setup(){
  SerialBT.begin("ESP32");
  myServo.attach(18);
}

void loop(){


  if(SerialBT.available()){
   int angle = SerialBT.parseInt();
    myServo.write(angle);
  }
  delay(20);
}