#include <Wire.h>
#include <Adafruit_APDS9960.h>

// Includi la libreria per controllare il sensore di gesti
Adafruit_APDS9960 apds;

// Pin per la striscia LED RGB
#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

// Variabili per il colore attuale
int redValue = 255;
int greenValue = 0;
int blueValue = 0;

void setup() {
  // Imposta i pin dei LED come output
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // Inizializza il monitor seriale
  Serial.begin(9600);
  
  // Inizializza il sensore APDS-9960
  if (!apds.begin()) {
    Serial.println("Errore: sensore APDS-9960 non trovato");
    while (1);
  }
  apds.enableGesture(true); // Abilita il riconoscimento dei gesti

  Serial.println("Sensore pronto! Fai un gesto sopra di esso.");
}

void loop() {
  // Variabile per rilevare il tipo di gesto
  uint8_t gesture = apds.readGesture();
  
  // Controlla il gesto
  if (gesture == APDS9960_UP) {
    Serial.println("Gesto: Su");
    incrementRed();
  } else if (gesture == APDS9960_DOWN) {
    Serial.println("Gesto: Giù");
    incrementGreen();
  } else if (gesture == APDS9960_LEFT) {
    Serial.println("Gesto: Sinistra");
    incrementBlue();
  } else if (gesture == APDS9960_RIGHT) {
    Serial.println("Gesto: Destra");
    resetColors();
  }

  // Aggiorna i valori RGB sul LED
  updateLED();
}

void incrementRed() {
  redValue = (redValue + 50) % 256;
}

void incrementGreen() {
  greenValue = (greenValue + 50) % 256;
}

void incrementBlue() {
  blueValue = (blueValue + 50) % 256;
}

void resetColors() {
  redValue = 255;
  greenValue = 0;
  blueValue = 0;
}

void updateLED() {
  analogWrite(RED_PIN, redValue);
  analogWrite(GREEN_PIN, greenValue);
  analogWrite(BLUE_PIN, blueValue);
}
