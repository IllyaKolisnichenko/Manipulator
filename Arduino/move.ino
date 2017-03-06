//Для нижнего шагового двигателя под ремень количество импульсов на 1мм-37.8228
//Для шагового двигателя на повороте количество импульсов на 1градус-34.4444
#include <Servo.h>

#define ENDSTOP_PIN 7 // пин концевика

Servo myservo1;//спареные нижние сервоприводы на 2-м пине
Servo myservo2;//2-й сервопривод от низа на 6-м пине
Servo myservo3;//3-й сервопривод от низа на 3-м пине
Servo myservo4;//сервопривод-клешня на 4-м пине

int dirPin_1 = 9;//dir сигнал нижнего шагового двигателя на ремнях
int stepPin_1 =8;//step сигнал нижнего шагового двигателя на ремнях

int dirPin_2 = 12;//dir сигнал нижнего шагового двигателя на ремнях
int stepPin_2 = 11;//step сигнал нижнего шагового двигателя на ремнях

int size=0;
void setup()
{
  Serial.begin(9600);
  //Назначение пинов и задание начального положения для сервоприводов
  myservo1.attach(2);
  myservo1.write(90);
  pinMode(52,OUTPUT);
  myservo2.attach(52);
  myservo2.write(121);
  
  myservo3.attach(3);
  myservo3.write(100);
  
  myservo4.attach(4);
  myservo4.write(42);
  pinMode(dirPin_1, OUTPUT);
  pinMode(stepPin_1, OUTPUT);
  
  pinMode(dirPin_2, OUTPUT);
  pinMode(stepPin_2, OUTPUT);
  
  pinMode(ENDSTOP_PIN,INPUT);
}
int v=0;
void relocation()
{ 
  if(v>0)
  {
      digitalWrite(dirPin_1, HIGH);
      for(int q=0;q<=2485;q++)
      {
          digitalWrite(stepPin_1, HIGH);
          digitalWrite(stepPin_1, LOW); // В этих двух строках LOW и HIGH дается команда шаговому двигателю двигаться
          delayMicroseconds(500);
      } 
  }
  for(int i=90,j=120;i<=120,j<=150;i++,j++)
  {
    if(i<120)
    {
      myservo1.write(i);
      delay(25);
    }
    if(j<150)
    {
      myservo2.write(j);
      delay(25);
    }
    if(j>=150 && i>=120){
        break;  
    }
  }
  for(int i=42;i>=13;i--)
  {
      myservo4.write(i);
      delay(25);
  }
  for(int i=120;i<=123;i++)
  {
      myservo1.write(i);
      delay(25);
  }
  for(int i=123,j=153;i>=90,j>=123;i--,j--)
  {
    if(i>90)
    {
      myservo1.write(i);
      delay(25);
    }
    if(j>123)
    {
      myservo2.write(j);
      delay(25);
    }
    if(j==123 && i==90){
        break;  
    }
  }
  myservo1.write(90);
  myservo2.write(125);
  myservo3.write(100);
  for(int i=120;i>=110;i--)
  {
      myservo2.write(i);
      delay(25);
  }
  for(int i=100;i>=95;i--)
  {
      myservo3.write(i);
      delay(25);
  }
  for(int j=90,i=110;j<=120,i<=142;j++,i++)
  {
      myservo1.write(j);
      myservo2.write(i);
      delay(25);
  }
  for(int i=13;i<=40;i++)
  {
      myservo4.write(i);
      delay(25);
  }
  for(int j=120,i=142;j>=90,i>=110;j--,i--)
  {
      myservo1.write(j);
      myservo2.write(i);
      delay(25);
  }
  for(int i=110;i<=120;i++)
  {
      myservo2.write(i);
      delay(25);
  }
  for(int i=95;i<=100;i++)
  {
      myservo3.write(i);
      delay(25);
  }
  v++;
}
bool flag=true;
void loop()
{
  if(flag==true)
  {
    digitalWrite(dirPin_1, LOW); // Смена направления
     while(digitalRead(ENDSTOP_PIN))
     {
        digitalWrite(stepPin_1, LOW);
        digitalWrite(stepPin_1, HIGH);
        delayMicroseconds(500);
     }
     delay(500);
     digitalWrite(dirPin_1, HIGH);
     for(int q=0;q<=567;q++)
     {
        digitalWrite(stepPin_1, HIGH);
        digitalWrite(stepPin_1, LOW); // В этих двух строках LOW и HIGH дается команда шаговому двигателю двигаться
        delayMicroseconds(500);
     }  
  }
  if(flag==true)
  {
    for(int i=0;i<=8;i++)
    {
        relocation();
    }
     
  }
  flag=false;
}
