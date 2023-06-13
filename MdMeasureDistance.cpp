#include <Arduino.h>
#include "M5All-In-One-Gadget.h"
#include "MdMeasureDistance.h"
#include "DrUltraSonic.h"

DrUltraSonic drul = DrUltraSonic(ECHO_PIN, TRIG_PIN);

double MdMeasureDistance::getDistance(){
    double distance = 0;
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    double tim = drul.measureReturnTime();
    if(tim >= 0){
        distance = (340.0 / 1000000) * tim * 0.5 * 100;
    }else{
        distance = 0;
    }
    return distance;
}