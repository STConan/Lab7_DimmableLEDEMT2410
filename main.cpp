/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>

#define RATE     500ms


int main()
{
    DigitalOut StatusLED(PA_3); //Light to indicate program functioning
    AnalogIn Potentiometer(PA_6); //Input potentiometer to dimm LED
    AnalogOut DimmableLED(PA_5); //LED to be dimmed

    while (true) {
        StatusLED.write(1); //Turn on status LED
        float DimmFactor = Potentiometer.read(); //Storing the reading from the potentiometer
        cout << "Potentiometer reading = " << (DimmFactor * 3.3) << " volts\n";
        cout << "Dimm Factor = " << (DimmFactor * 100.0) << "%\n";
        if (DimmFactor >= 0.8){ //Setting up the dimm based on the reading from potentiometer
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