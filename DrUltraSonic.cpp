#include <Arduino.h>
#include "M5All-In-One-Gadget.h"
#include "DrUltraSonic.h"

DrUltraSonic::DrUltraSonic(int echo_pin, int trig_pin){
    m_echo_pin = echo_pin;
    m_trig_pin = trig_pin;
    pinMode(m_echo_pin, INPUT);
    pinMode(m_trig_pin, OUTPUT);
}

double DrUltraSonic::measureReturnTime(){
    double t = 0;
    t = pulseIn(m_echo_pin, HIGH, 2000000);
    return t;
}