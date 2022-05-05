# DelayedActivation-Library

Sometimes things shall not be activated immediately but with some delay.
The purpose of this library is to have a mechanism, which gets activated
after a given number of trigger calls. Reset trigger calls can decrement
the counter up to deactivation.

So typically the workflow is as follows:
- init by the threshold values for activation and reset
- periodically call the reset trigger
- on activation call the activation trigger
  - if the threshold is reached a flag returns true
  - if activation calls are no longer given the reset trigger call
    decrements the counter 'til it gets below threshold and the flag
    returns false
- a clear routine resets the internal counters immediately

## DelayedActivation

The class implements a single check.

### Constructor
DelayedActivation(const uint32_t dwThresholdTrigger = 1,
		  const uint32_t dwThresholdReset   = 10)
- threshold for activation
  - the number specifiesthe number of calls 'til activation
- threshold for reset
  - the number of calls 'til the activation counter is decreased by one

### Methods
- Clear()
  - clear internal counters, full reset immediately
- GetActivationCounter()
  - returns internal counter for activation (raw value)
- IsActivated()
  - returns true if activation level is reached
- TriggerActivation()
  - trigger activation, count up by one
  - activation is given when counter reaches activation threshold
- TriggerReset()
  - increase reset counter by one
  - if reset threshold is reached, the activation counter is decreased by one
  - activation is reset when activation counter gets below activation threshold

## Releases
- 1.0.0 Initial release.

## How to install

[Installing Additional Arduino Libraries](https://www.arduino.cc/en/Guide/Libraries)
