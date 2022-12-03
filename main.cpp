/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>

// Blinking rate in milliseconds
#define RATE     500ms


int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut StatusLED(PA_3);
    AnalogIn Potentiometer(PA_6);
    AnalogOut DimmableLED(PA_5);

    while (true) {
        StatusLED.write(1);
        float DimmFactor = Potentiometer.read();
        cout << "Potentiometer reading = " << (DimmFactor * 3.3) << " volts\n";
        cout << "Dimm Factor = " << (DimmFactor * 100.0) << "%\n";
        cout << DimmFactor << endl;
        if (DimmFactor >= 0.8){
            DimmableLED.write(1.0);
        } else if (DimmFactor >= 0.6) {
            DimmableLED.write(0.8);
        } else if (DimmFactor >= 0.4) {
            DimmableLED.write(0.6);
        } else {
            DimmableLED.write(0.0);
        }
        ThisThread::sleep_for(RATE);
    }
    
}