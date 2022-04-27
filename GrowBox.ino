/*

AUTOMATED GROW BOX FOR MUSHROOMS project

@author: Keivan Amini, github: https://github.com/keivan-amini
@last review: 27-04-2022
@place: Ferrara, Italy

*/

//**************************************************


#include "DHT.h" // library for the humidity-temperature sensor
#include <LiquidCrystal_I2C.h> // library for the LCD Display
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


const float minimum_humidity = 80.00; // (%)
const float minimum_temp = 26; // (°C)


#define DHTPIN 10  // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

unsigned long myTime; // for the time management
extern volatile unsigned long timer0_millis;


// ************************************************


void setup() {
  Serial.begin(9600);
  Serial.println(F("Let's start!"));

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  dht.begin();

    lcd.init();                      
  // Print a message to the LCD.
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GROW BOX - PoliPolo");
  lcd.setCursor(0,1);
  lcd.print("PLAM and Phylor for");
   lcd.setCursor(0,2);
  lcd.print("LabAperto Ferrara");
   lcd.setCursor(0,3);
  lcd.print("PopUp 29 APR 2022");

}


// ***************************************************


void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temp) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, humidity);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(temp, humidity, false);

  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(temp);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

// Print measured temperature and humidity on the LCD Display

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperatura:");
  lcd.setCursor(13,0);
  lcd.print(temp);
  lcd.setCursor(19,0);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Umidita:");
  lcd.setCursor(9,1);
  lcd.print(humidity);
  lcd.setCursor(15,1);
  lcd.print("%");


// Set the lights ON for 12 hours, then turn them off
 Serial.print("Time: ");
 myTime = millis();

  Serial.println(myTime); // prints time since program started
  
  digitalWrite(4, LOW);

   if (myTime > 43200000) {
    digitalWrite(4, HIGH);
   }

// when 24h passed, impose the end of the loop
   if (myTime > 86400000) {
    noInterrupts ();
    timer0_millis = 0;
    interrupts ();
   }


// setting the atomizer and the fan ON if the humidity is under the minimum humidity
 if (humidity < minimum_humidity ) {
   digitalWrite(6, LOW);
   digitalWrite(7,LOW);
   lcd.setCursor(0,2);
  lcd.print("Umidificatore: ON");
   
}
 else {
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  lcd.setCursor(0,2);
  lcd.print("Umidificatore: OFF");
 }


// setting the hot resistance ON if the temperature is under the minimum temperature 
if (temp < minimum_temp ) {                 
   digitalWrite(5, LOW);
     lcd.setCursor(0,3);
  lcd.print("Resistenza: ON");
   
}
 else {
  digitalWrite(5, HIGH);
    lcd.setCursor(0,3);
  lcd.print("Resistenza: OFF");
 }
 
 }
