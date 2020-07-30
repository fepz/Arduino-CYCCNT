#include <Arduino.h>
#include "cyccnt.h"

uint32_t cycles;

void function(void);

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Testing CYCCNT.");
}
/**
 * Para medir la ejecución de un código en ciclos:
 *    STOPWATCH_RESET();
 *    cycles = CPU_CYCLES;
 *    // codigo que se quiera medir
 *    cycles = CPU_CYCLES - cycles;
 * 
 * En la variable cycles queda el número aproximado de ciclos de CPU consumidos.
 * La variable cycles debe de ser de tipo uint32_t.
 * 
 * A continuación un breve ejemplo:
 */
void loop() {
  STOPWATCH_RESET();
  cycles = CPU_CYCLES;
  function();
  cycles = CPU_CYCLES - cycles;
  Serial.print("Cycles: ");
  Serial.println(cycles, DEC); // imprime ciclos
  Serial.print("ms: ");
  Serial.println(cycles / 84000, DEC); // imprime ms aproximados
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