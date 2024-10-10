#include <Wire.h>
#include <U8glib.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#if DECODE_AC
#include <ir_Daikin.h>
#include <ir_Fujitsu.h>
#include <ir_Gree.h>
#include <ir_Haier.h>
#include <ir_Kelvinator.h>
#include <ir_Midea.h>
#include <ir_Toshiba.h>
#endif  // DECODE_AC

#define RECV_PIN 6  // IR receiver pin
#define BAUD_RATE 115200
#define CAPTURE_BUFFER_SIZE 1024

#if DECODE_AC
#define TIMEOUT 50U  // Higher timeout for AC
#else
#define TIMEOUT 15U  // Default timeout
#endif

#define MIN_UNKNOWN_SIZE 12  // Minimum size for unknown signals

// I2C pins
#define SCL_PIN 10
#define SDA_PIN 8

// Initialize the U8glib library for the 64x48 OLED display
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);  // Using default I2C pins

// Use turn on the save buffer feature for more complete capture coverage.
IRrecv irrecv(RECV_PIN, CAPTURE_BUFFER_SIZE, TIMEOUT, true);
decode_results results;  // Variable to store the IR results

void setup() {
  // Initialize serial communication
  Serial.begin(BAUD_RATE);
  while (!Serial) {
    delay(50);
  }

  // Initialize the I2C communication
  Wire.begin(SDA_PIN, SCL_PIN);  // Use the hardcoded pins

  // Display initialization message
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_6x10);  // Use a readable font
    u8g.drawStr(0, 10, "IRrecvDumpV2");
    u8g.drawStr(0, 20, "Waiting for IR input");
    u8g.drawStr(0, 30, "Pin 6");
  } while (u8g.nextPage());

  // Initialize the IR receiver
  irrecv.enableIRIn();  // Start the receiver
}

void loop() {
  // Clear the display
  u8g.firstPage();
  do {
    // Set text size and position
    u8g.setFont(u8g_font_6x10);
    
    if (irrecv.decode(&results)) {
      // Display IR received message
      u8g.drawStr(30, 10, "IR Radiometer");

      // Display the received IR value in HEX format
      char hexValue[16];
      sprintf(hexValue, "0x%08X", (unsigned long)results.value);  // Convert IR value to a string
      u8g.drawStr(10, 25, hexValue);

      // Resume receiving the next IR value
      irrecv.resume();

      // Print IR value to serial for debugging
      Serial.print("IR Value: ");
      Serial.println(hexValue);
    } else {
      // If no IR signal, display waiting message
      u8g.drawStr(30, 10, "Waiting for IR");
    }
  } while (u8g.nextPage());

  delay(200);  // Small delay for readability
}
