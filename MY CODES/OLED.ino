#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

bool showText = true;  // حالة النص: ظاهر أم لا
unsigned long previousMillis = 0;
const long interval = 500;  // مدة الوميض بالميلي ثانية (1 ثانية)

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("فشل في تشغيل الشاشة"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.display();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    display.clearDisplay();

    if (showText) {
      display.setCursor(0, 0);
      display.println(F("Hello, World!"));
    }

    display.display();
    showText = !showText; // قلب الحالة
  }
}
