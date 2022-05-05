//==============================================================================
// Delayed Activation Sample
//==============================================================================

//---| definitions |------------------------------------------------------------
#define CYCLE_TIME_MS       100
#define CYCLES_FOR_MIN(m)   ((m * 60000) / CYCLE_TIME_MS)
#define CYCLES_FOR_SEC(s)   ((s *  1000) / CYCLE_TIME_MS)

//---| includes |---------------------------------------------------------------
#if defined(ESP8266)
#  include <pgmspace.h>
#else
#  include <avr/pgmspace.h>
#endif
#include <Arduino.h>
#include <DelayedActivation.h>

//---| definitions |------------------------------------------------------------
#define INPUT_ALARM         D8

//---| classes |----------------------------------------------------------------
DelayedActivation       clsAlarm(5, CYCLES_FOR_SEC(5));

//------------------------------------------------------------------------------
// setup routine
//------------------------------------------------------------------------------
void setup()
{
  // start serial communication
  Serial.begin(9600);
  Serial.println("");

  // initialize internal LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  // initialize alarm input
  pinMode(INPUT_ALARM, INPUT);
  Serial.println("alarm input enabled");
}

//------------------------------------------------------------------------------
// main loop
//------------------------------------------------------------------------------
void loop()
{
  // check input
  if (digitalRead(INPUT_ALARM) == LOW)
  {
    clsAlarm.TriggerActivation();
  }
  
  // check for activation
  if (clsAlarm.IsActivated())
  {
    Serial.println("alarm is activated!");
  }

  // wait for next cycle
  clsAlarm.TriggerReset();
  delay(CYCLE_TIME_MS);
}

//===| eof - end of file |======================================================
