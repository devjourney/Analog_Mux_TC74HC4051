#include <Arduino.h>

int potentiometer = 0;
int photo_resistor = 0;

void setup() {
  Serial.begin(115200);
  // read from the only ADC on the ESP8266
  pinMode(A0, INPUT);
  // the three control inputs
  // see https://toshiba.semicon-storage.com/info/TC74HC4051AF_datasheet_en_20161018.pdf?did=16132&prodName=TC74HC4051AF
  pinMode(4, OUTPUT); // A on the mux - D2 on the MCU
  pinMode(5, OUTPUT); // B on the mux - D1 on the MCU
  pinMode(16, OUTPUT); // C on the mux - D0 on the MCU
  digitalWrite(16, LOW); // C will always be low b/c we only have devices on 0 and 3
}

void loop() {
  // select channel 0 and read the pot there
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  potentiometer = analogRead(A0);
  Serial.print("Pot=");
  Serial.print(potentiometer);
  // small delay to deal with capacitance during the switch
  delay(200);
  // select channel 3 and read the photoresistor there
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  photo_resistor = analogRead(A0);
  Serial.print(", Photoresistor=");
  Serial.println(photo_resistor);
  delay(1800);
}