int sensor=7; //output sensor PIR ke pin7 Arduino
int sensor_value; //variable untuk menyimpan nilai pembacaan sensor
 
void setup()
{
  pinMode(sensor,INPUT); // pin 7 sebagai input
  Serial.begin(9600); // menginisiasi komunikasi serial dengan laptop
}
 
void loop()
{
  sensor_value=digitalRead(sensor); // membaca nilai dari pin 7
  Serial.println(sensor_value);
}
