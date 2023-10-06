/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito electronica
   Codigo Tecnico: EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Examen Final 5ta Unidad.
   Nombre: Alvaro Josue Antonio Marroquin Corado
   Encardo: Profe. Alejandro Lopez Navas
   Fecha: 06/10/2023
*/

int sensorvalor;
int samplesnumber = 100;
const int sensor= A0; 


float V; 
float sen = 0.185; 
int sensorPin = A2;    
int valorsensor;
float voltaje, r1, r2;

void setup() {
 Serial.begin(9600);
 r2 = 10000; 
}

void loop() {

  sensorvalor= analogRead(sensor);
  V= fmap(sensorvalor,0,1023,0.0,25.0); 
  
  Serial.print("Voltaje = ");
  Serial.println(V);  

  float current = getCorriente(samplesnumber);
  float currentRMS = 0.707 * current; 
  float power = 230.0 * currentRMS;

   printm("intensidad", current, "A ,");
   printm("Irms", currentRMS, "A . ");
   printm("Potencia", power, "W");
   
 Serial.println();
  Serial.print("Valor aproximado de R1 = ");
  Serial.println(R1);
  delay(3000);

  float R2 = 10000;
  float Vout = analogRead(A2);
  float Vout3= Vout2/100000;
  float V1 = (R2*5) / Vout3;
  float R1 = V1 - R2;
  R1=R1+9;
  
}

float fmap(float x, float in_min, float in_max,
float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
 
}

float getCorriente(int SN){
  float Volt;
  float corriente = 0;

  for(int i=0; i < SN; i++)
  {
    Volt = analogRead(A1) * 5.0 / 1023.0;
    corriente += (Volt -2.5) / sen;
  }
  return(corriente / SN);
}
