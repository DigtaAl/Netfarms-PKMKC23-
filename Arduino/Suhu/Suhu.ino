#include <OneWire.h>
#include <DallasTemperature.h>
 
// sensor diletakkan di pin 2
#define ONE_WIRE_BUS 2
 
// setup sensor
OneWire oneWire(ONE_WIRE_BUS);
 
// berikan nama variabel,masukkan ke pustaka Dallas
DallasTemperature sensorSuhu(&oneWire);
 
float suhuSekarang;
 
void setup(void)
{
  Serial.begin(9600);
  sensorSuhu.begin();
}
 
void loop(void)
{
  
  suhuSekarang = ambilSuhu();
  Serial.println(suhuSekarang);     
  delay(2000);
}
 
float ambilSuhu()
{
   sensorSuhu.requestTemperatures();
   float suhu = sensorSuhu.getTempCByIndex(0);
   return suhu;   
}
