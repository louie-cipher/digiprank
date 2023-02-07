#include "DigiKeyboardPtBr.h"

char url[] = "https://www.youtube.com/watch?v=xm3YgoEiEDc";

void setup()
{
    pinMode(1, OUTPUT);

    DigiKeyboardPtBr.update();
    DigiKeyboardPtBr.sendKeyStroke(0);

    ledBlink(5);

    DigiKeyboardPtBr.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboardPtBr.delay(2200);

    DigiKeyboardPtBr.println("SndVol");
    DigiKeyboardPtBr.delay(600);

    keyUp(50);

    DigiKeyboardPtBr.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboardPtBr.delay(1600);

    DigiKeyboardPtBr.print("cmd /k start \"\" ");
    DigiKeyboardPtBr.print(url);
    DigiKeyboardPtBr.println(" && exit");

    ledBlink(16);
    keyUp(20);
}

void loop()
{
    bool first = true;

    while (true)
    {

        DigiKeyboardPtBr.sendKeyStroke(KEY_N, MOD_CONTROL_LEFT);
        ledBlink(5);

        if (first == true)
        {
            first = false;
            DigiKeyboardPtBr.print(url);
            DigiKeyboardPtBr.delay(100);
            DigiKeyboardPtBr.sendKeyStroke(KEY_A, MOD_CONTROL_LEFT);
            DigiKeyboardPtBr.delay(100);
            DigiKeyboardPtBr.sendKeyStroke(KEY_C, MOD_CONTROL_LEFT);
            DigiKeyboardPtBr.sendKeyStroke(KEY_ENTER);
        }
        else
        {
            DigiKeyboardPtBr.sendKeyStroke(KEY_V, MOD_CONTROL_LEFT);
            DigiKeyboardPtBr.delay(50);
            DigiKeyboardPtBr.sendKeyStroke(KEY_ENTER);
        }

        DigiKeyboardPtBr.delay(1500);
    }
}

void ledBlink(int times)
{
    for (int i = 0; i < times; i++)
    {
        digitalWrite(1, HIGH);
        DigiKeyboardPtBr.delay(250);
        digitalWrite(1, LOW);
        DigiKeyboardPtBr.delay(250);
    }
}

void keyUp(int times)
{
    for (int i = 0; i < times; i++)
    {
        DigiKeyboardPtBr.sendKeyStroke(KEY_UP_ARROW);
        DigiKeyboardPtBr.delay(50);
    }
}