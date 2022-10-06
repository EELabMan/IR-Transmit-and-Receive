/*
 * SimpleSender.cpp
 *
 *  Demonstrates sending IR codes in standard format with address and command
 *  An extended example for sending can be found as SendDemo.
 *
 *  Copyright (C) 2020-2021  Armin Joachimsmeyer
 *  armin.joachimsmeyer@gmail.com
 *
 *  This file is part of Arduino-IRremote https://github.com/Arduino-IRremote/Arduino-IRremote.
 *
 *  MIT License
 *  Modified by Tige Kelley for UTA EE Lab workshops
 */
#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.h>

const int BUTTON=2;    //The Button is connected to pin 2
boolean lastButton = LOW;    //Last Button State
boolean currentButton = LOW; //Current Button State
int ledMode = 0;             //Cycle between LED states


void setup() {
    pinMode(LED_BUILTIN, OUTPUT);  //pin 3 Arduino Uno

    Serial.begin(9600);

    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    /*
     * The IR library setup. That's all!
     */
    IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK); // Specify send pin and enable feedback LED at default feedback LED pin

    Serial.print(F("Ready to send IR signals at pin "));
    Serial.println(IR_SEND_PIN);

    pinMode (BUTTON, INPUT);  //Set button as input
}
     /*
  * Debouncing Function
  * Pass it the previous button state,
  * and get back the current debounced button state.
  */
  boolean debounce(boolean last)
  {
    boolean current = digitalRead(BUTTON);       //Read the button state
    if (last != current)                         //if it's different...
    {
      delay(5);                                  //wait 5ms
      current = digitalRead(BUTTON);             //read it again
    }
    return current;                              //return the current value
  }

  void setMode(int mode){
  //RED
  if (mode == 1)
  {
    Serial.println(F("Send NECRaw 0xEF10BF00"));
    IrSender.sendNECRaw(0xEF10BF00);
  }
  //GREEN
  else if (mode == 2)
  {
    Serial.println(F("Send NECRaw 0xEE11BF00"));
    IrSender.sendNECRaw(0xEE11BF00);
  }
  //BLUE
  else if (mode == 3)
  {
    Serial.println(F("Send NECRaw 0xED12BF00"));
    IrSender.sendNECRaw(0xED12BF00);
  }
  
  else if (mode == 4)
  {
    Serial.println(F("Send NECRaw 0xEB14BF00"));
    IrSender.sendNECRaw(0xEB14BF00);
  }
  
  else if (mode == 5)
  {
    Serial.println(F("Send NECRaw 0xEA15BF00"));
    IrSender.sendNECRaw(0xEA15BF00);
  }
  
  else if (mode == 6)
  {
    Serial.println(F("Send NECRaw 0xE916BF00"));
    IrSender.sendNECRaw(0xE916BF00);
  }
  
  else if (mode == 7)
  {
    Serial.println(F("Send NECRaw 0xEE11BF00"));
    IrSender.sendNECRaw(0xE718BF00);
  }

    else if (mode == 8)
  {
    Serial.println(F("Send NECRaw 0xE619BF00"));
    IrSender.sendNECRaw(0xE619BF00);
  }

    else if (mode == 9)
  {
    Serial.println(F("Send NECRaw 0xE51ABF00"));
    IrSender.sendNECRaw(0xE51ABF00);
  }
  //OFF (mode = 10)
  else
  {
    Serial.println(F("Send NECRaw 0xF906BF00"));
    IrSender.sendNECRaw(0xF906BF00);
  }
}
  





void loop() {
    

    

    currentButton = debounce(lastButton);           //read debounced state
    if (lastButton == LOW && currentButton == HIGH) //if it was pressed...
    {
        ledMode++;                                    //increment the LED value
        setMode(ledMode);                              //change the LED state
    }
    lastButton = currentButton;                     //reset button value
    //if you’ve cycled through the different options, reset the counter to 0
    if (ledMode == 10) ledMode = 0;
    

    delay(100);  // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
}
