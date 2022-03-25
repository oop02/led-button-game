#include <Arduino.h>

const uint8_t ledPins[] = {4, 5, 6, 7};
const uint8_t buttonPins[] = {8, 9, 10, 11};

void setup()
{
    for (auto pin : ledPins)
    {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, HIGH);
    }

    for (auto pin : buttonPins)
    {
        pinMode(pin, INPUT_PULLUP);
    }
}

void loop()
{
    const uint8_t ledOffIndex = random(4); // 0..3
    digitalWrite(ledPins[ledOffIndex], LOW);

    while (!digitalRead(buttonPins[ledOffIndex]))
    {
        delay(10);
    }

    digitalWrite(ledPins[ledOffIndex], HIGH);
}