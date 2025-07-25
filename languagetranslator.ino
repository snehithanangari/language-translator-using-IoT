#include <ESP8266TTS.h>  // For ESP8266 or use Talkie for ESP32
ESP8266TTS voice;

void setup() {
  Serial.begin(115200);
  voice.setSpeed(100);
}

void sayWord(String word) {
  voice.say(word.c_str());
}


