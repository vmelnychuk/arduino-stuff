#include <ctype.h>
#include <Arduino.h>
#include "Telegraph.h"

const char* LETTERS[] = {
    ".-", "-...", "-.-.", "-..", ".", // A-E
    "..-.", "--.", "....", "..", ".---", // F-J
    "-.-", ".-..", "--", "-.", "---", // K-O
    ".--.", "--.-", ".-.", "...", "-", // P-T
    "..-", "...-", ".--", "-..-", "-.--", // U-Y
    "--.." // Z
};

const char* DIGITS[] = {
    "-----", ".----", "..---", "...--", // 0-3
    "....-", ".....", "-....", "--...", // 4-7
    "---..", "----." // 8-9
};

Telegraph::Telegraph(const int dit_len) {
    dit_length = dit_len;
    dah_length = dit_length * 3;
    pinMode(LED_BUILTIN, OUTPUT);
}

void Telegraph::output_code(const char* code) {
    const unsigned int code_length = strlen(code);

    for (unsigned int i = 0; i < code_length; i++) {
        if (code[i] == '.') {
            dit();
        } else {
            dah();
        }
        // hardware related part
        if (i != code_length - 1) {
            delay(dit_length);
        }
    }
}

void Telegraph::dit() {
    Serial.print(".");
    output_symbol(dit_length);
}

void Telegraph::dah() {
    Serial.print("-");
    output_symbol(dah_length);
}

void Telegraph::output_symbol(const int length) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(length);
    digitalWrite(LED_BUILTIN, LOW);
}

void Telegraph::send_message(const char* message) {
    for (unsigned int i = 0; i < strlen(message); i++) {
        const char current_char = toupper(message[i]);
        if (isalpha(current_char)) {
            output_code(LETTERS[current_char - 'A']);
            delay(dah_length);
        } else if (isdigit(current_char)) {
            output_code(DIGITS[current_char - '0']);
            delay(dah_length);
        } else if (current_char == ' ') {
            Serial.print(" ");
            delay(dit_length * 7);
        }
    }
    Serial.println();
}



