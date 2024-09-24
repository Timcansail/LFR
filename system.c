#include "system.h"

void systemInit(void)
{
    // LED as output
    DDRD |= (1 << PD1);

    // Configure sensors as analog inputs
    DDRD &= ~(1 << PD2 | 1 << PD3 | 1 << PD4 | 1 << PD5 | 1 << PD6);

    // Configure button as input
    DDRC &= ~(1 << PC0);

    // Configure PWM for motors
    DDRA |= (1 << PA4 | 1 << PA5);

    // Enable PWM on TCA
}

void systemLedOn(void)
{
    PORTD |= (1 << PD1);
}

void systemLedOff(void)
{
    PORTD &= ~(1 << PD1);
}

uint16_t systemReadSensor(uint8_t sensor_num)
{
    // Select sensor channel
    ADMUX &= ~(0x07); // Clear the MUX3-MUX0 bits
    ADMUX |= (sensor_num & 0x07);

    // Start the ADC conversion
    ADCSRA |= (1 << ADSC);

    // Wait for conversion to complete
    while (ADCSRA & (1 << ADSC));

    return ADCW;
}

uint8_t systemReadButton(void)
{
    return (PINC & (1 << PC0)) != 0;
}

void systemSetMotorSpeed(uint8_t motor, uint8_t speed)
{
    // Set the PWM duty cycle for the specified motor
    if (motor == 0) {
        OCR0A = speed;
    } else if (motor == 1) {
        OCR0B = speed;
    }
}