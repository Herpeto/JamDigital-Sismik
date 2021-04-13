#include <TimerOne.h>
#include <ezButton.h>

long long int increment = 0;
long long int jam = 0, menit = 0, detik = 0;
int modeJam = 0;

const byte angka[10] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};
ezButton buttonMove(14);
ezButton buttonIncrement(15);
ezButton buttonDecrement(16);
  
void setup() {
  DDRD = 0b11111111;
  UCSR0B = 0b00000000;
  //button.setDebounceTime(100);

  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  //pinMode(14,INPUT);
  //pinMode(15,INPUT);
  //pinMode(16,INPUT);

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(counting);
  
}

void counting()
{
    increment += 1;
}

void gantiJam()
{
    static int gantiJam_set = 0; 
      if (buttonMove.isPressed() == HIGH)
      {
        gantiJam_set++;
      }
      if(gantiJam_set == 0)
      {
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          digitalWrite(11, LOW);
          digitalWrite(12, HIGH);
          digitalWrite(13, LOW);
          PORTD = angka[jam%10];
          delay(3);
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          digitalWrite(11, LOW);
          digitalWrite(12, LOW);
          digitalWrite(13, HIGH);
          PORTD = angka[jam/10];
          delay(3);
          if (buttonIncrement.isPressed() == HIGH)
          {
            jam++;
            if(jam == 25)
            {
              jam = 0;
            }
          }
          if (buttonDecrement.isPressed() == HIGH)
          {
            jam--;
            if(jam == -1)
            {
              jam = 24;
            }
          }
      }
      
      if(gantiJam_set == 1) // Menit
      {
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, HIGH);
          digitalWrite(11, LOW);
          digitalWrite(12, LOW);
          digitalWrite(13, LOW);
          PORTD = angka[menit%10];
          delay(3);
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          digitalWrite(11, HIGH);
          digitalWrite(12, LOW);
          digitalWrite(13, LOW);
          PORTD = angka[menit/10];
          delay(3);
          if (buttonIncrement.isPressed() == HIGH)
          {
            menit++;
            if(menit == 60)
            {
              menit = 0;
            }
          }
          if (buttonDecrement.isPressed() == HIGH)
          {
            menit--;
            if(menit == -1)
            {
              menit = 59;
            }
          }  
      }
      
      if (gantiJam_set == 2) // Detik
      {
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          digitalWrite(11, LOW);
          digitalWrite(12, LOW);
          digitalWrite(13, LOW);
          PORTD = angka[detik%10];
          delay(3);
          digitalWrite(8, LOW);
          digitalWrite(9, HIGH);
          digitalWrite(10, LOW);
          digitalWrite(11, LOW);
          digitalWrite(12, LOW);
          digitalWrite(13, LOW);
          PORTD = angka[detik/10];
          delay(3);
          if (buttonIncrement.isPressed() == HIGH)
          {
            detik++;
            if(detik == 60)
            {
              detik = 0;
            }
          }
          if (buttonDecrement.isPressed() == HIGH)
          {
            detik--;
            if(detik == -1)
            {
              detik = 59;
            }
          }  
      }
      if(gantiJam_set == 3)
      {
        increment = (jam * 3600) + (menit*60) + (detik);
        gantiJam_set = 0;
        modeJam++;
      }
}



void tampilJam()
{
    if (increment < 60)
      {
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        PORTD = angka[increment%10];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        PORTD = angka[increment/10];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        PORTD = angka[0];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        PORTD = angka[0];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        PORTD = angka[0];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);
        PORTD = angka[0];
        delay(3);
      }
      else if (increment < 3600)
      {
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        PORTD = angka[(increment%60)%10];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        PORTD = angka[(increment%60)/10];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        PORTD = angka[(increment/60)%10];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        PORTD = angka[(increment/60)/10];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        PORTD = angka[0];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);
        PORTD = angka[0];
        delay(3);
      }
      else if (increment < 86400)
      {
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        PORTD = angka[((increment%3600)%60)%10];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        PORTD = angka[((increment%3600)%60)/10];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        PORTD = angka[((increment%3600)/60)%10];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        PORTD = angka[((increment%3600)/60)/10];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        PORTD = angka[(increment/3600)%10];
        delay(3);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);
        PORTD = angka[(increment/3600)/10];
        delay(3);
      }
      else
      {
        increment = 0;  
      }
}

void loop() 
{   
   buttonMove.loop();
   buttonIncrement.loop();
   buttonDecrement.loop();

   if(modeJam == 0)
   {
      gantiJam();
   }
   if(modeJam == 1)
   {
      tampilJam();
   }
}
