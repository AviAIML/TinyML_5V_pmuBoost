
// This sketch shows how to program pin# 2 to provide 5V supply.

#include <NDP.h>                                            // Arduino_library/libraries/NDP/src/
#include <NDP_utils.h>                                      // Arduino_library/libraries/TinyML_NDP_utils/src
#include <Arduino.h>
#include "TinyML_init.h"                                    // Arduino_library/libraries/TinyML_lowpower_lib
#include "SAMD21_init.h"                                    // Arduino_library/libraries/TinyML_lowpower_lib
#include "NDP_PMU.h" 
#include "PMIC_init.h"

#define DO_NOT_WAIT_FOR_SERIAL_PORT 0                       // For battery powered autonomus usage, use this option
#define WAIT_FOR_SERIAL_PORT 1                              // For debugging purposes use this option, program will wait until serial port is turned on, Arduino IDE Tools --> Serial Monitor

void setup(void) {
  SAMD21_init(WAIT_FOR_SERIAL_PORT);                        // Setting up SAMD21, the program will wait with Red LED
  PMIC_init();                                              // PMIC initalization
  pinMode(ENABLE_5V, OUTPUT);
  digitalWrite(ENABLE_5V, LOW);                             // The 5V switch is turned on so 5V appears on pin#2 of TinyML board so an external actuator can be powered on     
  pmuBoost();
  Serial.println("PMU Boost to provide 5V on Pin # 2");
  for (int i=0; i<10; i++){
    delay(1000);                                             // Waiting 10 seconds to turn off 5V supply.    
    Serial.print("Counting down : ");
    Serial.println(i);
  }
  pmuCharge();                                              // This tricks the board to turn off the 5V supply
  Serial.print("5V supply turned off ");
}

void loop() {
}
