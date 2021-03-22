#include <Arduino.h>
#include <kmotor.h>

char state;
Kmotor _motor(1);

void setup()
{
    Serial.begin(9600);
    _motor.init();
    /// These lines are used for testing boards and motors. If you want to check, uncomment these below lines and check whether motors can run for 2s.
    // Serial.println("Running for 2s...");
    // _motor.run(0, 200); delay(2000); 
    // _motor.stop();
}

void loop()
{
    state = (Serial.available() > 0)? Serial.read(): 0;
    /*
        state can be (called by button):
        +) D-Pad: F, C, M, L, R, E, P, B, S
        +) Car steering: n-S
        +) Running: N-S
        +) Led: Y-y
        +) Sound: T-t
        +) Switch vertical: U-u
        +) Switch horizontal: O-o
        For more infomation, download Robo Control app from Kidscode (Android only)
    */
    if (state) Serial.println(state);
    switch (state)
    {
        case 'F':
            _motor.run(0, 255);
            break;
        case 'B':
            _motor.run(1, 200);
            break;
        case 'C': case 'L':
            _motor.run(2, 200);
            break;
        case 'M': case 'R':
            _motor.run(3, 200);
            break;
        case 'S':
            _motor.stop();
    }
}