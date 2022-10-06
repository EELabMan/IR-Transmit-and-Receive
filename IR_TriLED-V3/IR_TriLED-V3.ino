/*      
*  IR read codes     
*  by Hanie kiani     
*  Edited by Todd Kelley to update to IRremote  Version 3 / Use the small Remotes       
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
   Serial.print("IR HEX Code is 0x");
   Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);    
   delay(100);
      
       switch(IrReceiver.decodedIRData.decodedRawData){     
         case 0xEF10BF00: //Keypad button "1"     
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
              
           
         case 0xEE11BF00: //Keypad button "2"
            //turn off all LEDS
            analogWrite(bluePin, 0); 
            analogWrite(redPin, 0);     
            analogWrite(greenPin,0);
            delay(10);      
            //set color Blue     
            analogWrite(redPin, 0);     
            analogWrite(greenPin,0);     
            analogWrite(bluePin, 254);
            break;      
                   
         case 0xED12BF00: //Keypad button "3"
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
                 
         case 0xEB14BF00: //Keypad button "4"
            //turn off all LEDS
            analogWrite(bluePin, 0); 
            analogWrite(redPin, 0);     
            analogWrite(greenPin,0);
            delay(10);      
            //set color White     
           analogWrite(redPin, 254);     
           analogWrite(greenPin,254);     
           analogWrite(bluePin, 254);
           break;      
         
         case 0xEA15BF00: //Keypad button "5"
            //turn off all LEDS
            analogWrite(bluePin, 0); 
            analogWrite(redPin, 0);     
            analogWrite(greenPin,0);
            delay(10);      
            //set color      
           analogWrite(redPin, 254);     
           analogWrite(greenPin,254);     
           analogWrite(bluePin, 0);
           break; 

           case 0xE916BF00: //Keypad button "6"
            //turn off all LEDS
            analogWrite(bluePin, 0); 
            analogWrite(redPin, 0);     
            analogWrite(greenPin,0);
            delay(10);      
            //set color      
           analogWrite(redPin, 254);     
           analogWrite(greenPin,0);     
           analogWrite(bluePin, 254);
           break; 

           case 0xE718BF00: //Keypad button "7"
            //turn off all LEDS
            analogWrite(bluePin, 0); 
            analogWrite(redPin, 0);     
            analogWrite(greenPin,0);
            delay(10);      
            //set color     
           analogWrite(redPin, 0);     
           analogWrite(greenPin,254);     
           analogWrite(bluePin, 254);
           break; 

           case 0xE619BF00: //Keypad button "8"
            //turn off all LEDS
            analogWrite(bluePin, 0); 
            analogWrite(redPin, 0);     
            analogWrite(greenPin,0);
            delay(10);      
            //set color     
           analogWrite(redPin, 100);     
           analogWrite(greenPin,100);     
           analogWrite(bluePin, 100);
           break; 

           case 0xE51ABF00: //Keypad button "9"
            //turn off all LEDS
            analogWrite(bluePin, 0); 
            analogWrite(redPin, 0);     
            analogWrite(greenPin,0);
            delay(10);      
            //set color      
           analogWrite(redPin, 100);     
           analogWrite(greenPin,10);     
           analogWrite(bluePin, 10);
           break; 

           case 0xF906BF00: //Keypad button "Stop / Mode"
            //turn off all LEDS
            analogWrite(bluePin, 0); 
            analogWrite(redPin, 0);     
            analogWrite(greenPin,0);
            delay(10);      
            //set led off     
           analogWrite(redPin, 0);     
           analogWrite(greenPin,0);     
           analogWrite(bluePin, 0);
           break; 
         }      
       IrReceiver.resume();      
   }     
}      
