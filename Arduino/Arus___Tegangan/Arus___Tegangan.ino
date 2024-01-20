#define ANALOG_IN_PIN A1

const int pinADC = A0;

int sensitivitas = 100; //tegantung sensor arus yang digunakan, yang ini 5A
int nilaiadc= 00;
int teganganoffset = 2500; //nilai pembacaan offset saat tidak ada arus yang lewat
int adc_value = 0;

double tegangan = 00;
double nilaiarus = 00;
 
float adc_voltage = 0.0;
float in_voltage = 0.0;
float R1 = 30000.0;
float R2 = 7500.0; 
float ref_voltage = 5.0;

void setup(){
Serial.begin(9600); //baud komunikasi serial monitor 9600bps
}

void data_olah(){
  nilaiadc = analogRead(pinADC);
  tegangan = (nilaiadc / 1024.0) * 5000;
  nilaiarus = ((tegangan - teganganoffset) / sensitivitas);
}

void loop(){
   data_olah();
      // Read the Analog Input
   adc_value = analogRead(ANALOG_IN_PIN);
   
   // Determine voltage at ADC input
   adc_voltage  = (adc_value * ref_voltage) / 1024.0; 
   
   // Calculate voltage at divider input
   in_voltage = adc_voltage / (R2/(R1+R2)) ; 
   
   // Print results to Serial Monitor to 2 decimal places
  Serial.print("Input Tegangan = ");
  Serial.print(in_voltage, 2);
 
  Serial.print("\t Arus = ");
  Serial.println(nilaiarus,3);

  delay(1000);
}
