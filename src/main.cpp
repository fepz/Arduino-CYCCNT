#include <Arduino.h>
#include "cyccnt.h"

uint32_t ulDelayTime;

void function(void);

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Testing CYCCNT.");
}

void loop() {
  STOPWATCH_RESET();
  ulDelayTime = CPU_CYCLES;
  function();
  ulDelayTime = CPU_CYCLES - ulDelayTime;
  Serial.print("Cycles: ");
  Serial.println(ulDelayTime, DEC);
  Serial.print("ms: ");
  Serial.println(ulDelayTime / 84000, DEC);
  delay(1);
}

void function() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("Led ON");
  delay(250);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  Serial.println("Led OFF");
  delay(250);                       // wait for a second
}