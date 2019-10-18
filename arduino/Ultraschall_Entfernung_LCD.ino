#include <Wire.h>  
#include <LiquidCrystal_I2C.h> 
#include <NewPing.h>
 
// Definieren der Konstanten für Trigger und Echo
#define  TRIGGER_PIN  11
#define  ECHO_PIN     10
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters).
                         //Maximum sensor distance is rated at 400-500cm.

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display 
 
// Objekt für den Sensor deklarieren
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Setup für NewPing (Pins und maximale Distanz).
 
// Deklarieren der Variablen für die Messwerte
int DistanceIn;
int DistanceCm;
 
void setup()   // Setup um den Arduino zu konfigurieren
{
   lcd.init();                      // initialize the lcd  
   lcd.backlight(); 
   lcd.setCursor(1,0); 
   lcd.print("Ultraschall Meter");
   lcd.setCursor(0,1); 
   lcd.print("Die Entfernung ist:");    
}
 
 
void loop()  // Loop für die Messung der Werte, läuft endlos
{
  delay(100);   // Wartet 100 Milisekunden zwischen den Pings (ca. 10 Pings pro Sekunde). 29 Millisekunden ist der kürzest mögliche Delay zwischen zwei Pings.
  DistanceIn = sonar.ping_in();
   lcd.setCursor(0,2); 
   lcd.print("Ping: ");
   lcd.print(DistanceIn);  // Konvertiert die Ping Zeit in die Entfernung und gibt das Resultat über die Serielleschnittstelle zurück 
                            // (0 = outside set distance range, no ping echo)
   lcd.print(" in     ");
  
   delay(100);  // Wartet 100 Milisekunden zwischen den Pings (ca. 10 Pings pro Sekunde). 29 Millisekunden ist der kürzest mögliche Delay zwischen zwei Pings.
   DistanceCm = sonar.ping_cm();
   lcd.setCursor(0,3);
   lcd.print("Ping: ");
   lcd.print(DistanceCm); 
   lcd.println(" cm  ");  
}
