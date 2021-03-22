#include "kmotor.h"

int mdig[] = {7, 8}, manl[] = {6, 3};

Kmotor::Kmotor(bool msg)
{
    _msg = msg;
}

void Kmotor::init()
{
    for (int i = 0; i < 2; i++)
    {
        pinMode(mdig[i], OUTPUT); pinMode(manl[i], OUTPUT);
    }
}

void Kmotor::engine(int cnt, int spd)
{
    digitalWrite(mdig[cnt], bool(spd >= 0));
    analogWrite(manl[cnt], abs(spd));
}

void Kmotor::run(char mode, int spd)
{
    switch(mode)
    {
        case 'F': // fwd
            Kmotor::engine(0, spd);
            Kmotor::engine(1, spd);
            break;
        case 'B': //bwd
            Kmotor::engine(0, -spd);
            Kmotor::engine(1, -spd);
            break;
        case 'L': //turn left
            Kmotor::engine(0, -spd);
            Kmotor::engine(1, spd);
            break;
        case 'R': // turn right
            Kmotor::engine(0, spd);
            Kmotor::engine(1, -spd);
            break;
        case 'C': // fwd-left
            Kmotor::engine(0, 0);
            Kmotor::engine(1, spd);
            break;
        case 'M': // fwd-right
            Kmotor::engine(0, spd);
            Kmotor::engine(1, 0);
            break;
        case 'E': // bwd-left
            Kmotor::engine(0, 0);
            Kmotor::engine(1, -spd);
            break;
        case 'P': // fwd-right
            Kmotor::engine(0, -spd);
            Kmotor::engine(1, 0);
            break;
        case 'S':
            Kmotor::engine(0, 0);
            Kmotor::engine(1, 0);
    }
}