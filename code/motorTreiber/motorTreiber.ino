#include <Arduino.h>

// ESP32 Pinout
int LED_l = 4;
int LED_r = 21;


int ENA = 22;
int ENB = 23;
int motor1pin1 = 17;
int motor1pin2 = 5;
int motor2pin1 = 18;
int motor2pin2 = 19;

char temp;

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_l, OUTPUT);
  pinMode(LED_r, OUTPUT);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1,   OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(ENA,   OUTPUT);
  pinMode(ENB, OUTPUT);


  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

}

void loop() {
  // put your main code here, to run repeatedly:

  //Controlling speed (0   = off and 255 = max speed):

  //analogWrite(ENA, 200); //ENA pin
  //analogWrite(ENB, 200); //ENB pin


  if (SerialBT.available()) {
    temp = SerialBT.read();
    Serial.write(temp);
  }

  if ( temp == 'g')
  {

    analogWrite(ENA, 200); //ENA pin
    analogWrite(ENB, 200); //ENB pin

    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);

    digitalWrite(LED_l, HIGH);
    digitalWrite(LED_r, HIGH);
  }

  if ( temp == 's')
  {
    analogWrite(ENA, 200); //ENA pin
    analogWrite(ENB, 200); //ENB pin

    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);

    temp = 'x';
  }

  if ( temp == 'r')
  {

    analogWrite(ENA, 150); //ENA pin
    analogWrite(ENB, 150); //ENB pin

    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);

    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);

    digitalWrite(LED_l, HIGH);

    delay(50);
  }
  if ( temp == 'l')
  {
    analogWrite(ENA, 150); //ENA pin
    analogWrite(ENB, 150); //ENB pin

    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);

    digitalWrite(LED_l, HIGH);

    delay(50);
  }
  else
  {
    delay(500);
    
    digitalWrite(LED_l, LOW);
    digitalWrite(LED_r, LOW);

    delay(500);

    digitalWrite(LED_l, HIGH);
    digitalWrite(LED_r, HIGH);

    delay(500);
    
    digitalWrite(LED_l, LOW);
    digitalWrite(LED_r, LOW);

    delay(500);

    digitalWrite(LED_l, HIGH);
    digitalWrite(LED_r, HIGH);

    delay(500);

    digitalWrite(LED_l, LOW);
    digitalWrite(LED_r, LOW);
  }


  delay(20);
}

/*
  if (Serial.available()) {
  SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
  Serial.write(SerialBT.read());
  }
*/

/*



  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
   digitalWrite(motor2pin2, LOW);
  delay(3000);

  digitalWrite(motor1pin1,   LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
   digitalWrite(motor2pin2, LOW);
  delay(3000);

*/
