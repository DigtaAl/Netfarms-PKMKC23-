// Library
#include <Wire.h>                   // Memanggil library wire.h

// Pin Sensor
#define Ldr1 A1                     // Deklarasi LDR pada pin A0
#define Ldr2 A0
#define PinTeg A2                   // Deklarasi pin tegangan pada pin A2
const int pinArus = A3;             // Deklarasi pin arus pada pin A3
const int relay1 = 2;               // Deklarasi relay pada pin D2
const int relay2 = 3; 
int PIR1 = 4;                       // Deklarasi PIR pada pin D4
int PIR2 = 5;

// Pembacaan Sensor
int statusPir1 = 0;                 // Variabel status pir
int statusPir2 = 0;
int nilaiLdr1;                      // Variabel nilai ldr
int nilaiLdr2;
float hasilTeg = 0.0;
float hasilArus = 00;
int relayON = LOW;                  // relay nyala
int relayOFF = HIGH;                // relay mati

// Perhitungan
float Vmodul = 0.0; 
float R1 = 30000.0; //30k
float R2 = 7500.0; //7500 ohm resistor, 
int value1 = 0;
int sensitivitas = 100; //tegantung sensor arus yang digunakan, yang ini 5A
int nilaiadc1 = 00;
int teganganoffset = 2500; //nilai pembacaan offset saat tidak ada arus yang lewat
double tegangan1 = 00;

void data_olah_arus_tegangan(){
  nilaiadc1 = analogRead(pinArus);
  tegangan1 = (nilaiadc1 / 1024.0) * 5000;
  hasilArus = ((tegangan1 - teganganoffset) / sensitivitas);
  value1 = analogRead(PinTeg);        // Instruksi membaca status pinTeg 
  Vmodul = (value1 * 5.0) / 1024.0;
  hasilTeg = Vmodul / (R2/(R1+R2));
}

void setup() {
  Serial.begin(9600);      // Baud komunikasi serial pada 9600
  pinMode(Ldr1, INPUT);    // Deklarasi LDR sebagai Input
  pinMode(Ldr2, INPUT);
  pinMode(PIR1, INPUT);    // Deklarasi PIR sebagai Input
  pinMode(PIR2, INPUT);
  pinMode(PinTeg, INPUT);  // Deklarasi Pinteg sebagai Input
  pinMode(pinArus, INPUT); // Deklarasi Pinteg sebagai Input
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, relayOFF);
  digitalWrite(relay2, relayOFF);
}

void loop() {
  data_olah_arus_tegangan();
  nilaiLdr1 = analogRead(Ldr1);       // Instruksi membaca nilai analog LDR
  nilaiLdr2 = analogRead(Ldr2);
  statusPir1 = digitalRead(PIR1);     // Instruksi membaca status PIR 
  statusPir2 = digitalRead(PIR2);
  //digitalWrite(relay1, relayON); relay nyala
  //digitalWrite(relay1, relayOFF); relay mati
  Serial.print("Nilai LDR1: ");       // Menampilkan Nilai analog LDR pada Serial Monitor
  Serial.print(nilaiLdr1);
  Serial.print(" || Nilai LDR2: "); 
  Serial.println(nilaiLdr2);
  Serial.print("Status PIR1: ");      // Menampilkan Nilai analog LDR pada Serial Monitor
  Serial.print(statusPir1);
  Serial.print(" || Status PIR2: "); 
  Serial.println(statusPir2);
  if(nilaiLdr1 <= 550 || nilaiLdr2 <= 550){
    Serial.print("Danger!!");
    digitalWrite(relay1, relayON);
    delay(1000);
    digitalWrite(relay1, relayOFF);
    delay(1000);
    digitalWrite(relay1, relayON);
    delay(1000);
    digitalWrite(relay1, relayOFF);
    }
   else{
    digitalWrite(relay1, relayOFF);
    }
  //Serial.print("Tegangan: ");         // Menampilkan Nilai tegangan pada Serial Monitor
  //Serial.print(hasilTeg);
 //Serial.print(" || Arus: "); 
  //Serial.println(hasilArus);
  delay(100);
}
