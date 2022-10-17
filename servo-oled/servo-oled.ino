#include <Servo.h>
#include <SPI.h>
// The I2C library
#include <Wire.h>
// Core graphics library
#include <Adafruit_GFX.h>
// Hardware-specific library
#include <Adafruit_SSD1306.h>

const int PIN_CTRL = A7;
const int PIN_SERVO = 3;
const unsigned int DISPLAY_WIDTH = 128, DISPLAY_HEIGHT = 64;
const int FOREGROUND = SSD1306_WHITE, BACKGROUND = SSD1306_BLACK;
// -1 means that we share the Arduino reset pin
const int OLED_RESET = -1;
// The I2C selection address
const int DISPLAY_ADDRESS = 0x3C;

Servo servo1;
Adafruit_SSD1306 display(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire, OLED_RESET);

void setup() { 
  pinMode(PIN_CTRL, INPUT);
  servo1.attach(PIN_SERVO);

  // SSD1306_SWITCHCAPVCC = generate display voltage from the provided 3.3V one
  // SSD1306_EXTERNALVCC = use the external display voltage
  if(!display.begin(SSD1306_SWITCHCAPVCC, DISPLAY_ADDRESS)) {
    // Blink forever
    pinMode(LED_BUILTIN, OUTPUT);
    bool state = HIGH;
    while(true) {
      digitalWrite(LED_BUILTIN, state);
      state = !state;
      delay(1000);
    }
  }
}

void loop() {
  display.clearDisplay();
  
  int ctrl = analogRead(PIN_CTRL);
  int angle = map(ctrl, 0, 1023, 0, 180);
  servo1.write(angle);
  
  displayText("Angle: ", 0, 0);
  displayText(String(angle), 0, 32);
  display.display();
  
  // Wait for Servo movement
  delay(15);
}

void displayText(String value, int xpos, int ypos) {
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(xpos, ypos);
  display.println(value);
}
