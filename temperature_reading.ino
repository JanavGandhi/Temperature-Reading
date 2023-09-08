#define BLYNK_TEMPLATE_ID "TMPL3tNqjsrOr"
#define BLYNK_TEMPLATE_NAME "DHT"
#define BLYNK_AUTH_TOKEN "SiQAJX1HYQ1-QfcHqBW3jBx6Wmt4PwHu"
#include <DHT.h>
#include <BlynkSimpleEsp8266.h>
#define DHTPIN 4 // Data pin is connected to D2 on ESP
#define DHTTYPE DHT11 // Name the sensor as an object
DHT dht(DHTPIN, DHTTYPE);
char auth[]="SiQAJX1HYQ1-QfcHqBW3jBx6Wmt4PwHu";
char ssid[] = "Redmi Note 9";
char pass[]="12345678";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test Successful!");
  Blynk.begin(auth,ssid,pass);
  Serial.print("Blynk connected successfully");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Something is not working as intended.\n");
    return; 
  }
  Serial.println("/nHumidity: ");
  Serial.print(h);
  Serial.print("%");
  Serial.println("Temperature");
  Serial.print(t);
  Serial.print("degrees celsius.");
  Blynk.virtualWrite(V0,t);
  Blynk.virtualWrite(V1,h);
  delay(2000);
}