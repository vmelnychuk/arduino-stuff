#include "Telegraph.h"

const unsigned int BAUD_RATE = 9600;
const unsigned int DIT_LENGTH = 200;

Telegraph telegraph(DIT_LENGTH);

void setup() {
    Serial.begin(BAUD_RATE);
}

void loop() {
    telegraph.send_message("SOS SOS SOS");
    delay(5000);
}
