const int temp_sens=A0, Heater=13, Fan=6;
#include<LiquidCrystal.h>
float MinTemp=20, MaxTemp=25;
LiquidCrystal LCD(12,11,5,4,3,2);
void setup()
{
  LCD.begin(16,2);
  pinMode(Heater,OUTPUT);
  pinMode(Fan,OUTPUT);
  LCD.print("Room Temperature(C):");
  LCD.setCursor(2,1);
  LCD.print(MinTemp);
  LCD.print("-");
  LCD.print(MaxTemp);
  delay(1000);
}
void loop()
{
  float eqv_volt, SensorTemp;
  eqv_volt=analogRead(temp_sens)*5.0/1023;
  SensorTemp=100.0*eqv_volt-50.0;
  LCD.clear();
  LCD.print("Sensor Reading:");
  LCD.setCursor(2,1);
  LCD.print(SensorTemp);
  LCD.print("C");
  delay(2000);
  if(SensorTemp>MaxTemp)
  {
    LCD.clear();
    LCD.print("Temp is Higher!");
    LCD.setCursor(0,1);
    LCD.print("Turn on Fan!");
    for(int i=0;i++;i<=255)
    {
      analogWrite(Fan,i);
    }
    delay(2000);
  }
  else if(SensorTemp<MinTemp)
  {
    LCD.clear();
    LCD.print("Temp is Lower!");
    LCD.setCursor(0,1);
    LCD.print("Turn on Heater!");
    digitalWrite(Heater,HIGH);
    delay(3000);
    LCD.clear();
    LCD.print("Now Temp is OK!");
    LCD.setCursor(0,1);
    LCD.print("Turn off Heater!");
    delay(1000);
    digitalWrite(Heater,LOW);
    LCD.clear();
  }
  else if(SensorTemp>MinTemp && SensorTemp<MaxTemp)
  {
    LCD.clear();
    LCD.print("Temp is normal!");
    LCD.setCursor(0,1);
    LCD.print("Turn off all");
    delay(1000);
    LCD.clear();
  }
    else
    {
      LCD.clear();
      LCD.print("Something went wrong");
      LCD.setCursor(0,1);
      LCD.print("Wrong in the circuit");
      delay(1000);
      LCD.clear();
    }
    delay(1000);
  }
