//  Pins
//  BT VCC to Arduino 5V out. 
//  BT GND to GND
//  Arduino Digital 8  - BT TX no need voltage divider 
//  Arduino Digital 9  - BT RX through a voltage divider (5v to 3.3v)
//
 
#include <AltSoftSerial.h>
AltSoftSerial BTserial; //BT serial 
 
char c=' '; // Reading the serial output
int cnt; // Counter variable
String buff=""; // Buffer String
 
void setup(){
    Serial.begin(9600);
    BTserial.begin(9600);
    BTserial.println("AT+DISC?");   
}
void loop(){
  if (BTserial.available()>0){
        c = BTserial.read();
        Serial.write(c); 
        buff += c;
  }
   
   cnt=buff.length();
   
   if(buff.charAt(cnt-5)=='D' && buff.charAt(cnt-4)=='I' && buff.charAt(cnt-3)=='S' && buff.charAt(cnt-2)=='C' && buff.charAt(cnt-1)=='E'){
    Serial.println();
    buff="";
    delay(1000);
    BTserial.println("AT+DISC?");
  }        
}
