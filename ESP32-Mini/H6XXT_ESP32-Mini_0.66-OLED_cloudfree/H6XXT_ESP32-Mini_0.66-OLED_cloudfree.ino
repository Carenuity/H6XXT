//... By Timothy Mwala
//  Insatll the IRremoteESP8266 library from:https://github.com/crankyoldgit/IRremoteESP8266


#include <Arduino.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>
#include <U8g2lib.h>

// Pin connected to the IR receiver
#define RECV_PIN 16

// OLED Display Setup (U8g2)
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

// IR Receiver Setup
IRrecv irrecv(RECV_PIN); // Create an IR receiver object
decode_results results;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  Serial.println("IR Receiver Initialized. Ready to receive signals...");

  // Initialize IR receiver
  irrecv.enableIRIn();

  // Initialize OLED
  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB08_tr); // Set font
  u8g2.clearBuffer();
  u8g2.drawStr(35, 43, "PRESSREMOTE...");
  u8g2.sendBuffer(); // Update display
}

void loop() {
  if (irrecv.decode(&results)) {
    // Decode the received signal
    unsigned long buttonCode = results.value;

    // Clear the display buffer
    u8g2.clearBuffer();

    // Display raw HEX value on OLED
    u8g2.setCursor(35, 45);
    u8g2.print("HEX Code:");
    u8g2.setCursor(35, 58);
    u8g2.print("0x");
    u8g2.print(buttonCode, HEX); // Display the HEX value

    // Update OLED display
    u8g2.sendBuffer();

    // Debugging in Serial Monitor
    Serial.print("Decoded HEX: 0x");
    Serial.println(buttonCode, HEX);

    // Prepare for next IR signal
    irrecv.resume();
  }
}
