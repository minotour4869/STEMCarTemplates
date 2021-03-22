#include <Arduino.h>
#include <kmotor.h>

int initial_speed = 225;

Kmotor _motor(1);
int ml = 0, mr = 4;
float avg[] = {900, 900, 900, 900}; // adjust this array for calibrate line sensor, you can use Serial Monitor to read the value and adjust it
bool state[5];

void setup()
{
    _motor.init(); Serial.begin(9600);
    for (int i = 0; i < 4; i++) pinMode(sens[i], INPUT);
    delay(1000);
}

void loop()
{
    int ml = 4, mr = -1;
    for (int i = 0; i < 4; i++)
    {
        float val = analogRead(sens[i]);
        Serial.print(val); Serial.print(' ');
        if (val < avg[i]) // if value read by led are smaller than avg, then it'll count as black, otherwise it's white
        {
            ml = min(ml, i); mr = max(mr, i);
        }
    }
    Serial.println();
    _motor.engine(0, 25*max(4 - ml, 3)); _motor.engine(1, 25*max(3, mr + 1));
    delay(50);
}
