#include <DHT.h>

#define DHTPIN 2      // Pin tempelkan sensor DHT11 di pin 2
#define DHTTYPE DHT11 // Jenis sensor DHT

DHT dht(DHTPIN, DHTTYPE);

int relayPin = 7;   // Pin tempelkan relay di pin 7

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(relayPin, OUTPUT);
}

void loop() {
  // Membaca suhu dari sensor DHT11
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Gagal membaca data dari sensor DHT!");
    return;
  }

  Serial.print("Suhu: ");
  Serial.println(temperature);

  if (temperature > 31.0) {
    digitalWrite(relayPin, HIGH); // Mengaktifkan relay
    Serial.println("Relay ON");
  } else {
    digitalWrite(relayPin, LOW);  // Mematikan relay
    Serial.println("Relay OFF");
  }

  delay(2000); // Menggunakan delay agar pembacaan suhu tidak terlalu cepat
}
