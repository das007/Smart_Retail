//const int Intrupt_input_tilt = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

const int piezo_sensing_pin=A5;   //Analog pin
const int temp_sensing_pin=A3;   //Analog pin
const int temp_ac_ctrl=4;
const int Li_fi_led=3;

//DRAGON BOARD IP/OP PIN
const int piezo_reset_pin=A2;    //Analog pin
//const int Li_fi_on=A0;
const int Li_fi_mode=A1;

//Output pin
//int dragon_tilt=11;
int dragon_temp=10;
int dragon_piezo=9;


#include <avr/sleep.h>
// variables will change:
volatile int buttonState = 0;         // variable for reading the pushbutton status
float temp=0;
int Li_fi_mode1=0;
int initial_weight=0;
int current_weight=0;
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  
    Serial.begin(9600);
    //Input from Ardino to Ardino
    pinMode(piezo_sensing_pin,INPUT);
    pinMode(temp_sensing_pin,INPUT);
    
    //Arduino input from dragon board
    pinMode(piezo_reset_pin,INPUT);
   // pinMode(Li_fi_on,INPUT);
    pinMode(Li_fi_mode,INPUT);
    //Arduino output
    pinMode(temp_ac_ctrl, OUTPUT);
    //Arduino output to dragon
    //pinMode(dragon_tilt, OUTPUT);
    pinMode(dragon_temp, OUTPUT);
    pinMode(dragon_piezo, OUTPUT);
    
  // initialize the pushbutton pin as an input:
//  pinMode(Intrupt_input_tilt, INPUT);
   //pinMode(normal_sec_pin, INPUT);
   pinMode(Li_fi_led, OUTPUT);
   
  // Attach an interrupt to the ISR vector
 // attachInterrupt(0, pin_ISR, CHANGE);
  
}

void loop() {
  // Nothing here!
  
   // Temp analysis part
    temp=analogRead(temp_sensing_pin);
    Serial.println(temp);
    if(temp>175)  //175
      {digitalWrite(dragon_temp,HIGH);
       digitalWrite(temp_ac_ctrl,LOW);
      }   
    else
      { digitalWrite(dragon_temp,LOW);
        if(temp>170) //170
          digitalWrite(temp_ac_ctrl,HIGH);
       else
          digitalWrite(temp_ac_ctrl,LOW);
      }
f
     // Piezo analysis part
//     current_weight=analogRead(piezo_sensing_pin);
//     if(piezo_reset_pin>300)
//        initial_weight=current_weight;
//
//    current_weight=analogRead(piezo_sensing_pin);    
      if(current_weight)
        {digitalWrite(dragon_piezo,HIGH);}//Serial.println(current_weight); sleep();} 
     else
        {digitalWrite(dragon_piezo,LOW);
         
          }

     //Li-Fi
    // Li_fi_mode1=1;
     if(analogRead(Li_fi_mode)>280)    //if(Li_fi_mode1==1)
        {//Serial.println(Li_fi_mode1);
          digitalWrite(Li_fi_led, HIGH);
          //Serial.println(analogRead(Li_fi_mode));
         delay(250);
         digitalWrite(Li_fi_led, LOW);
         delay(249);
          }
     else
        {digitalWrite(Li_fi_led, HIGH);
          //Serial.println(analogRead(Li_fi_mode));
         delay(500);
         digitalWrite(Li_fi_led, LOW);
         delay(498);
          }
 /* }
  else
  {
    digitalWrite(dragon_tilt,LOW);
    sleep();   
    
  }*/
}

/*void pin_ISR() {
  buttonState = digitalRead(Intrupt_input_tilt);
 digitalWrite(ledPin, buttonState);
  Serial.println("int");
   digitalWrite(dragon_tilt,HIGH);
}*/
void sleep()
{
   set_sleep_mode(SLEEP_MODE_PWR_DOWN);   // sleep mode is set here
 
    sleep_enable();    
}


