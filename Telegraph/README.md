# Telegraph
This is Telegraph project.
It transforms string lieral to morze code with output to build-in led.


## Small part of usage
```code
Telegraph telegraph(200);
telegraph.send_message("Hello, world!");
```

Pathes
- /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/cores/arduino
- /Applications/Arduino.app/Contents/Java/hardware/tools/avr/avr/include
- /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/variants/standard
- /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/libraries

1. copy header file

    cp /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/variants/standard/pins_arduino.h
    /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/cores/arduino

2. compile code

```shell
g++ 
-I /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/cores/arduino
-I /Applications/Arduino.app/Contents/Java/hardware/tools/avr/avr/include
-I /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/variants/standard 
-I /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/libraries
Telegraph.cpp
```

3. check output there are some warnings and errors it's ok, just check out if there is no errors in your code

4. install library: copy files to local sketchbook `/Users/<YOUR-USER-NAME>/Documents/Arduino/libraries/Telegraph`


```c++
#include "Telegraph.h"

const unsigned int BAUD_RATE = 9600;
const unsigned int DIT_LENGTH = 200;

Telegraph telegraph(DIT_LENGTH);
void setup() {
    Serial.begin(BAUD_RATE);
}
void loop() {
    telegraph.send_message("Hello, world!");
    delay(5000);
}
```
