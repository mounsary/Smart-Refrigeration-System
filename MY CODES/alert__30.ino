#define BLYNK_TEMPLATE_ID "TMPL2EVx0xru4"
#define BLYNK_TEMPLATE_NAME "ttgo esp32"
#define BLYNK_AUTH_TOKEN "0mJs7Wa4FvaDVVh-qrd7RPDio9wFZWJo"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// بيانات الواي فاي
char ssid[] = "Galaxy Wifi";
char pass[] = "12062023";


// منفذ GPIO المتصل به حساس DS18B20
#define ONE_WIRE_BUS 21

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

BlynkTimer timer;

// دالة لإرسال درجة الحرارة إلى Blynk
void sendTemp() {
  sensors.requestTemperatures(); 
  float tempC = sensors.getTempCByIndex(0);
  
  // التحقق من قراءة صحيحة لدرجة الحرارة
  if (tempC != DEVICE_DISCONNECTED_C) {
    // إرسال درجة الحرارة إلى المنفذ الافتراضي V0
    Blynk.virtualWrite(V0, tempC); 
    
    Serial.print("Temperature is: ");
    Serial.print(tempC);
    Serial.println(" C");
    
    // إرسال تنبيه إذا تجاوزت درجة الحرارة 30 درجة مئوية
    if (tempC > 30) {
      Blynk.logEvent("high_temp_alert");
      Serial.println("High temperature alert sent!");
    }
  } else {
    Serial.println("Error: Could not read temperature data.");
  }
}

void setup() {
  // بدء الاتصال التسلسلي للمراقبة
  Serial.begin(1155200); 
  
  // تهيئة حساس الحرارة
  sensors.begin();
  
  // الاتصال بشبكة الواي فاي و Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  // إعداد مؤقت (Timer) لتنفيذ دالة sendTemp() كل 10 ثواني
  timer.setInterval(10000L, sendTemp); 
}

void loop() {
  Blynk.run();
  timer.run();
}
