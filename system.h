#ifndef SYSTEM_H
#define SYSTEM

#include <avr/io.h>
#include <stdint.h>

void systemInit(void);
void systemLedOn(void);
void systemLedOff(void);
uint16_t systemReadSensor(uint8_t sensorNum);
bool systemReadButton(void);
void systemSetMotorSpeed(uint8_t motor, uint8_t speed);

#endif