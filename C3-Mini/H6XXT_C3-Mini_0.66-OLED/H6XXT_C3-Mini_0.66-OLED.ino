#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

#define RECV_PIN 2   // GPIO2 on Lolin C3 Mini for IR receiver
#define BAUD_RATE 115200
#define CAPTURE_BUFFER_SIZE 1024

#define TIMEOUT 15U  // Suits most messages, while not swallowing many repeats.
#define MIN_UNKNOWN_SIZE 12

#define OLED_RESET 0  // GPIO0 on Lolin C3 Mini for OLED Reset
Adafruit_SSD1306 display(OLED_RESET);

IRrecv irrecv(RECV_PIN, CAPTURE_BUFFER_SIZE, TIMEOUT, true);
decode_results results;

void setup()
{
  Serial.begin(BAUD_RATE);
  while (!Serial)  // Wait for the serial connection to be established.
    delay(50);

  Wire.begin();  // Initialize I2C with SDA on GPIO4 and SCL on GPIO5

  display.println();
  display.print("IRrecvDumpV2 is now running and waiting for IR input on Pin ");
  display.println(RECV_PIN);

  // Initialize the OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  

  // Set the minimum unknown size for IR decoding
  irrecv.setUnknownThreshold(MIN_UNKNOWN_SIZE);

  // Enable IR reception
  irrecv.enableIRIn();
}

void loop()
{
  delay(200);
  if (irrecv.decode(&results))
  {
    // Print the received IR value on the OLED display
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(40, 8);
    display.print("Remote ");
    display.setCursor(40, 18);
    display.setTextSize(1);
    display.print(results.value, HEX);
    display.println("");
    irrecv.resume();  // Receive the next value
    display.display();
  }
  delay(200);
}
