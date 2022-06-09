#define BLYNK_TEMPLATE_ID "" // add your template id here
#define BLYNK_DEVICE_NAME "" // add your device name here
#define BLYNK_AUTH_TOKEN "" // add your auth token here

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = BLYNK_AUTH_TOKEN; 
char ssid[] = "";//Enter your WIFI name
char pass[] = "";//Enter your WIFI password

bool ledbutton = 0;

#define led D6 
// here, my led is connected to pin D6, feel free to switch this to any pin you want to use.
//do note that pin D0 is the internal pin, and can be used to test if your project is working.

BLYNK_WRITE(V0) {
  ledbutton = param.asInt();
}
// get value of virual pin 0, which we have set up before in the dashboard.
// this is the virtual pin that we can use to control the led.

void setup() {
    Serial.begin(9600);
    Serial.setDebugOutput(true);
    pinMode(ledbutton, OUTPUT);
    Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

}

void LedSwitch(){
    if (ledbutton == 1) {
        digitalWrite(led, HIGH);
    }
    else {
        digitalWrite(led, LOW);
    }
}

void loop() {
    Blynk.run();
    LedSwitch();
}

