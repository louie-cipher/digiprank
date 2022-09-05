#include "DigiKeyboardPtBr.h"

void setup()
{
    pinMode(1, OUTPUT);

    DigiKeyboardPtBr.update();
    DigiKeyboardPtBr.sendKeyStroke(0);

    for (int i = 0; i < 5; i++)
    {
        digitalWrite(1, HIGH);
        DigiKeyboardPtBr.delay(200);
        digitalWrite(1, LOW);
        DigiKeyboardPtBr.delay(200);
    }

    DigiKeyboardPtBr.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboardPtBr.delay(2200);

    DigiKeyboardPtBr.println("SndVol");
    DigiKeyboardPtBr.delay(600);

    keyUp(50);

    DigiKeyboardPtBr.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboardPtBr.delay(1600);

    DigiKeyboardPtBr.println("cmd /k start \"\" https://www.youtube.com/watch?v=FOMGYHD1kY0 && exit");

    DigiKeyboardPtBr.delay(5000);
    keyUp(20);
}

void loop()
{
    bool first = true;

    while (true)
    {

        DigiKeyboardPtBr.sendKeyStroke(KEY_N, MOD_CONTROL_LEFT);
        DigiKeyboardPtBr.delay(1500);

        if (first == true)
        {
            first = false;
            DigiKeyboardPtBr.print("https://www.youtube.com/watch?v=FOMGYHD1kY0");
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

void keyUp(int times)
{
    for (int i = 0; i < times; i++)
    {
        DigiKeyboardPtBr.sendKeyStroke(KEY_UP_ARROW);
        DigiKeyboardPtBr.delay(50);
    }
}
