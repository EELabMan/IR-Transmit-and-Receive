/*      
*  IR read codes     
*  by Hanie kiani     
*  https://electropeak.com/learn/        
*/ 
    
#include <IRremote.h>     
int IR_RECEIVE_PIN =6;     
int bluePin = 5;     
int greenPin = 10;        
int redPin = 9;     
//IRrecv irrecv(RECV_PIN);  // Depreciated     
// decode_results results;  // Depreciated  
void setup(){     
 Serial.begin(9600);     
 IrReceiver.enableIRIn();     
 pinMode(redPin, OUTPUT);     
 pinMode(greenPin, OUTPUT);     
 pinMode(bluePin, OUTPUT); 
 IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);    
}     
void loop(){ 


if (IrReceiver.decode()){
   Serial.println(IrReceiver.decodedIRData.decodedRawData);    
   delay(100);
      
       switch(IrReceiver.decodedIRData.decodedRawData){     
         case 3977404806: //Keypad button "1"     
            //turn off all LEDS
            analogWrite(bluePin, 0); 
            analogWrite(redPin, 0);     
            analogWrite(greenPin,0);
            delay(10);     
            analogWrite(bluePin, 0);  //set color red     
            analogWrite(redPin, 254);     
            analogWrite(greenPin,0);     
            analogWrite(bluePin, 0);
         break;     
              
           
         case 3960693126: //Keypad button "2"
            //turn off all LEDS
            analogWrite(bluePin, 0); 
            analogWrite(redPin, 0);     
            analogWrite(greenPin,0);
            delay(10);      
            //set color White     
            analogWrite(redPin, 0);     
            analogWrite(greenPin,0);     
            analogWrite(bluePin, 254);
            break;      
                   
         case 3994116486: //Keypad button "3"
            //turn off all LEDS
            analogWrite(bluePin, 0); 
            analogWrite(redPin, 0);     
            analogWrite(greenPin,0);
            delay(10);      
            //set color Green     
            analogWrite(redPin, 0);     
            analogWrite(greenPin,254);     
            analogWrite(bluePin, 0);
            break;      
                 
         case 4010828166: //Keypad button "4"
            //turn off all LEDS
            analogWrite(bluePin, 0); 
            analogWrite(redPin, 0);     
            analogWrite(greenPin,0);
            delay(10);      
            //set color Blue     
           analogWrite(redPin, 254);     
           analogWrite(greenPin,254);     
           analogWrite(bluePin, 254);
           break;      
         }      
       IrReceiver.resume();      
   }     
}      
