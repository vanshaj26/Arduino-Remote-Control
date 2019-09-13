#include <IRremote.h>
#define irPin 2
IRrecv irrecv(irPin);
decode_results results;
#define r1 6
int light1 = LOW;
#define r2 5
int light2 = LOW;
#define r3 4
int light3 = LOW;
#define r4 3
int light4 = LOW;
void setup() 
{
    irrecv.enableIRIn();
    pinMode(r1, OUTPUT); 
    pinMode(r2, OUTPUT);
    pinMode(r3, OUTPUT);
    pinMode(r4, OUTPUT);   
    digitalWrite(r1,HIGH);
    digitalWrite(r2,HIGH);
    digitalWrite(r3,HIGH);
    digitalWrite(r4,HIGH);
    Serial.begin(9600);
}
void loop() {

   if (irrecv.decode(&results)) {
    Serial.println(results.value,HEX);
      switch (results.value) {
            case 0x73E1A187:
            digitalWrite(r1,HIGH);
            light1 = ~ light1;
            delay(150);
            break;
            case 0x117DD:
            digitalWrite(r2,light2);
            light2 = ~ light2;
            delay(250);
            break;
            case 0x97ED:
            digitalWrite(r3,light3);
            light3 = ~ light3;
            delay(250);
            break;
            case 0x197CD:
            digitalWrite(r4,light4);
            light4 = ~ light4;
            delay(250);
            break;
           }
 
   irrecv.resume();
   }
}
